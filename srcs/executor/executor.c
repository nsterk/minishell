/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/06 15:30:02 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * ? testing
*/
static void	print_stuff(t_lexer *lexer)
{
	int		i;

	i = 0;
	while (lexer->tokens[i].word != NULL)
	{
		printf("print_stuff: %s\n", lexer->tokens[i].word);
		i++;
	}
}

/**
 * Wait for processes to end.
 * 	Loop over each process:
 * 		1. Check if error on wait.
 * 		2. Save next process.
 * 		3. Free current process.
 * 		4. Go to next process.
 * 	Check if child process exited normally:
 * 		- Y => set last pid to exit status.
 * 		- N => WTERMSIG determines which signal was raised by the child process.
*/
static void	st_wait_processes(t_proc *proc, t_data_exe *data_exe)
{
	int		status;
	t_proc	*next;

	while (proc)
	{
		if (waitpid(proc->pid, &status, 0) < 0)
			exit_error(errno, "wait_processes", NULL);
		next = proc->next;
		free(proc);
		proc = next;
	}
	if (WIFEXITED(status))
		data_exe->last_pid = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data_exe->last_pid = WTERMSIG(status) + 128;
}

/**
 * Create new process structure.
 * 	1. Allocate new process struct.
 * 	2. Check malloc error.
 * 	3. Check if process:
 * 		- N => set proc to new proc
 * 		- Y => set next proc to new proc and proc to next proc.
 * 	4. Return (new) process.
*/
static t_proc	*st_new_process(t_proc *proc)
{
	t_proc	*new_proc;

	new_proc = (t_proc *)malloc(sizeof(t_proc));
	check_malloc(new_proc, "new_process");
	new_proc->next = NULL;
	if (!proc)
		proc = new_proc;
	else
	{
		proc->next = new_proc;
		proc = proc->next;
	}
	return (proc);
}

/**
 * Piped command function.
 * 	Loop over command struct:
 * 		1. Create new process struct.
 * 		2. If first command is true:
 * 			- Set current to process,
 * 			- Set first command to false.
 * 		3. Execute piped commands with new process struct.
 * 		4. Go to next command.
 * 	Close fd.
*/
static void	st_piped_cmd(t_proc **current, t_cmd *cmd, t_data_exe *data_exe)
{
	t_proc	*proc;
	int		fd;
	bool	first_cmd;

	proc = NULL;
	fd = 0;
	first_cmd = true;

	// ? loop over cmd struct
	while (cmd)
	{
		// ? malloc new fork
		proc = st_new_process(proc);

		// ? 
		if (first_cmd)
		{
			*current = proc;
			first_cmd = false;
		}

		// ?
		fd = exec_piped_cmd(proc, cmd, data_exe, fd);
		cmd = cmd->next;
	}
	close(fd);
}

/**
 * Simple command function.
 * 	1. If special builtin (cd, export, unset, exit):
 * 		- redirect input,
 * 		- redirect output, 
 * 		- check which builtin and execute, and
 * 		- return NULL (as simple command so we dont need to have a struct)
 * 	2. Create new process struct as NULL (simple command)
 * 	3. Fork new process.
 * 	4. Check fork pid:
 * 		- < 0 => exit with error errno.
 * 		- = 0 (child):
 * 			a. redirect input
 * 			b. redirect output
 * 			c. execute command
 * 	5. Return process struct.
*/
static t_proc	*st_simple_cmd(t_cmd *cmd, t_data_exe *data_exe)
{
	t_proc	*proc;

	// ? special builtin?
	if (special_builtin(cmd->exec->cmd))
	{
		// ? redirect input => dup
		if (redirect_in(cmd->in, STDIN_FILENO, data_exe))
			return (NULL);

		// ? redirect output => dup
		if (redirect_out(cmd->out, STDOUT_FILENO, data_exe))
			return (NULL);

		// ? exec builtin
		check_builtin(cmd, data_exe);

		// ? return NULL =>
		return (NULL);
	}

	// ? new fork (NULL)
	proc = st_new_process(NULL);
	
	// ? fork process
	proc->pid = fork();
	
	// ? fork pid < 0 ? => exit_error
	if (proc->pid < 0)
		exit_error(errno, "simple_cmd", NULL);

	// ? fork pid = 0 (child) ?
	else if (proc->pid == CHILD)
	{
		// ? redirect input => dup
		if (redirect_in(cmd->in, STDIN_FILENO, data_exe))
			exit(data_exe->last_pid);
		
		// ? redirect output => dup
		if (redirect_out(cmd->out, STDOUT_FILENO, data_exe))
			exit(data_exe->last_pid);
		
		// ? exec cmd
		execute_cmd(cmd, cmd->exec, data_exe);
	}
	
	// ? return fork (= NULL)
	return (proc);
}

/**
 * Main executor function.
 * 	1. Init. here_doc, sets last pid to 1 and returns.
 * 	2. Init. environment paths.
 * 	3. Simple command or pipes?
 * 		- simple cmd => process is null
 * 		- piped cmds => process not null
 * 	4. If pipes, wait processes to finish.
 * 	5. Free executor data.
*/
// void	executor(t_lexer *lexer, t_cmd *cmd, t_data_exe *data_exe)
void	executor(t_lexer *lexer)
{
	t_proc 		*proc;
	t_cmd 		*cmd;
	t_data_exe	*data_exe;

	cmd = NULL;
	data_exe = NULL;

	data_exe->envp = NULL;
	data_exe->envp = lexer->envp;

	// ? init heredoc
	if (init_heredoc(cmd))
	{
		data_exe->last_pid = 1;
		return ;
	}

	// ? init paths
	data_exe->paths = init_paths(data_exe->envp);

	// ? check if has next cmd
	if (!cmd->next)

		// ? no, exec simple cmd
		proc = st_simple_cmd(cmd, data_exe);

	else
		// ? yes, exec cmds in pipeline
		st_piped_cmd(&proc, cmd, data_exe);

	// ? wait processes if pipes
	if (proc)
		st_wait_processes(proc, data_exe);

	// ? free paths
	ft_free_array(data_exe->paths);
}
