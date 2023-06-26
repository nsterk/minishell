
#include "executor.h"

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
static void	st_wait_processes(t_proc *proc, t_data *data)
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
		data->last_pid = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		data->last_pid = WTERMSIG(status) + 128;
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
static void	st_piped_cmd(t_proc **current, t_cmd *cmd, t_data *data)
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
		fd = exec_piped_cmd(proc, cmd, data, fd);
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
static t_proc	*st_simple_cmd(t_cmd *cmd, t_data *data)
{
	t_proc	*proc;

	if (cmd->args && special_builtin(cmd->args[0]))
	{
		if (redirect_in(cmd->in, STDIN_FILENO, data))
			return (NULL);
		if (redirect_out(cmd->out, STDOUT_FILENO, data))
			return (NULL);
		check_builtin(cmd, data);
		return (NULL);
	}
	proc = st_new_process(NULL);
	proc->pid = fork();
	if (proc->pid < 0)
		exit_error(errno, "simple_cmd", NULL);
	else if (proc->pid == CHILD)
	{
		if (redirect_in(cmd->in, STDIN_FILENO, data))
			exit(1); //! changed this because we gave exit status 0 if file not found error for indirect
		if (redirect_out(cmd->out, STDOUT_FILENO, data))
			exit(1);
		execute_cmd(cmd, data);
	}
	return (proc);
}

/**
 * Main executor function.
 * 	1. Init. here_doc (see init_heredoc)
 * 		- If failure
 * 			=> set last pid to 1 and return.
 * 	2. If cmd doesnt have execution command (i.e. parsing error || empty)
 * 		=> return.
 * 	3. Signal
 * 	2. Init. environment paths.
 * 	3. Simple command or pipes?
 * 		- simple cmd => process is null
 * 		- piped cmds => process not null
 * 	4. If pipes, wait processes to finish.
 * 	5. Free executor data.
*/

void	executor(t_data *data)
{
	t_proc 		*proc;
	t_cmd 		*tmp;

	tmp = data->cmd;
	proc = NULL; //! init to NULL so that we don't get stuck in st_wait_processes
	if (init_heredoc(tmp))
	{
		data->last_pid = 1;
		return ;
	}
	// if (!tmp->args)
	// 	return ;
	signal(SIGQUIT, sigquit_handler);
	data->paths = init_paths(data->envp);
	if (!tmp->next)
		proc = st_simple_cmd(tmp, data);
	else
		st_piped_cmd(&proc, tmp, data);
	if (proc)
		st_wait_processes(proc, data);
	ft_free_array(data->paths);
}
