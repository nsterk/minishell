/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/07 15:43:32 by abeznik       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * ? testing
*/
// static void	print_stuff(t_lexer *lexer)
// {
// 	int		i;

// 	i = 0;
// 	while (lexer->tokens[i].word != NULL)
// 	{
// 		printf("print_stuff: %s\n", lexer->tokens[i].word);
// 		i++;
// 	}
// }

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
	while (cmd)
	{
		proc = st_new_process(proc);
		if (first_cmd)
		{
			*current = proc;
			first_cmd = false;
		}
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

	if (special_builtin(cmd->exec->cmd))
	{
		if (redirect_in(cmd->in, STDIN_FILENO, data_exe))
			return (NULL);
		if (redirect_out(cmd->out, STDOUT_FILENO, data_exe))
			return (NULL);
		check_builtin(cmd, data_exe);
		return (NULL);
	}
	proc = st_new_process(NULL);
	proc->pid = fork();
	if (proc->pid < 0)
		exit_error(errno, "simple_cmd", NULL);
	else if (proc->pid == CHILD)
	{
		if (redirect_in(cmd->in, STDIN_FILENO, data_exe))
			exit(data_exe->last_pid);
		if (redirect_out(cmd->out, STDOUT_FILENO, data_exe))
			exit(data_exe->last_pid);
		execute_cmd(cmd, cmd->exec, data_exe);
	}
	return (proc);
}

/**
 * ? testing function
*/
static void	st_init_lexer_data(t_lexer *lexer, t_cmd **cmd, \
			t_data_exe **data_exe, t_exec **exec)
{
	t_data_exe 	*tmp_data;
	t_cmd 		*tmp_cmd;
	t_exec 		*tmp_exec;

	tmp_data = (t_data_exe *)malloc(sizeof(t_data_exe));
	tmp_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	tmp_exec = (t_exec *)malloc(sizeof(t_exec));

	// Save lexer envp to tmp 
	// Save tmp to data_exe
	tmp_data->envp = (char **)malloc(sizeof(char **) * 1024);
	tmp_data->envp = lexer->envp;
	*data_exe = tmp_data;

	// Save token word to exec cmd
	tmp_exec->cmd = (char *)malloc(sizeof(char *) * ft_strlen(lexer->tokens->word));
	tmp_exec->cmd = lexer->tokens->word;
	*exec = tmp_exec;

	// Save exec to cmd exec
	tmp_cmd->exec = (t_exec *)malloc(sizeof(t_exec));
	tmp_cmd->exec = *exec;
	*cmd = tmp_cmd;
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
	t_exec		*exec;

	st_init_lexer_data(lexer, &cmd, &data_exe, &exec);

	if (init_heredoc(cmd))
	{
		data_exe->last_pid = 1;
		return ;
	}
	data_exe->paths = init_paths(data_exe->envp);
	if (!cmd->next)
		proc = st_simple_cmd(cmd, data_exe);
	else
		st_piped_cmd(&proc, cmd, data_exe);
	if (proc)
		st_wait_processes(proc, data_exe);
	ft_free_array(data_exe->paths);
}
