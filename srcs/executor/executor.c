/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <abeznik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:41:10 by abeznik       #+#    #+#                 */
/*   Updated: 2023/01/04 15:25:08 by abeznik       ########   odam.nl         */
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

static void	st_wait_processes(t_proc *proc, t_exec *exec)
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
		exec->last_pid = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exec->last_pid = WTERMSIG(status) + 128;
}

static t_proc	*st_new_process(t_proc *proc)
{
	t_proc	*new_proc;

	new_proc = (t_proc *)malloc(sizeof(t_proc));
	ft_check_malloc(new_proc, "new_process");
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

static void	st_piped_cmd(t_proc **current, t_cmd *cmd, t_exec *exec)
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
		proc = new_process(proc);

		// ? 
		if (first_cmd)
		{
			*current = proc;
			first_cmd = false;
		}

		// ?
		fd = exec_piped_cmd(proc, cmd, exec, fd);
		cmd = cmd->next;
	}
	close(fd);
}

// TODO fix struct
static t_proc	*st_simple_cmd(t_cmd *cmd, t_exec *exec)
{
	t_proc	*proc;

	// ? builtin?
	if (special_builtin(exec->cmd))
	{
		// ? redirect input => dup
		if (redirect_in(cmd->in, STDIN_FILENO, exec))
			return (NULL);

		// ? redirect output => dup
		if (redirect_out(cmd->out, STDOUT_FILENO, exec))
			return (NULL);

		// ? exec builtin
		check_builtin(cmd, exec);

		// ? return NULL =>
		return (NULL);
	}

	// ? new fork (NULL)
	proc = new_process(NULL);
	
	// ? fork process
	proc->pid = fork();
	
	// ? fork pid < 0 ? => exit_error
	if (proc->pid < 0)
		exit_error(errno, "simple_cmd", NULL);

	// ? fork pid = 0 (child) ?
	else if (proc->pid == CHILD)
	{
		// ? redirect input => dup
		if (redirect_in(cmd->in, STDIN_FILENO, exec))
			exit(exec->last_pid);
		
		// ? redirect output => dup
		if (redirect_out(cmd->out, STDOUT_FILENO, exec))
			exit(exec->last_pid);
		
		// ? exec cmd
		execute_cmd(cmd, exec);
	}
	
	// ? return fork (= NULL)
	return (proc);
}

void	executor(t_lexer *lexer, t_cmd *cmd, t_exec *exec)
// void	executor(char *cmd, char *option, const char *STRING, t_lexer *lexer) // ? testing
{
	// ? testing
	// printf("\tInput executor: [ %s %s %s ]\n", cmd, option, STRING);
	
	// ? testing
	printf("[0] %s\n", lexer->tokens[0].word);
	printf("[1] %s\n", lexer->tokens[1].word);
	printf("[2] %s\n", lexer->tokens[2].word);
	printf("[3] %s\n", lexer->tokens[3].word);

	t_proc *proc;

	// ? init heredoc
	if (init_heredoc(cmd))
	{
		exec->last_pid = 1;
		return ;
	}

	// ? init paths
	exec->paths = init_paths(exec->env);

	// ? check if has next cmd
	if (!cmd->next)

		// ? no, exec simple cmd
		proc = st_simple_cmd(cmd, exec);

	else
		// ? yes, exec cmds in pipeline
		st_piped_cmd(&proc, cmd, exec);

	// ? wait processes if pipes
	if (proc)
		st_wait_processes(proc, exec);

	// ? free paths
	ft_free_char_array(exec->paths);
}
