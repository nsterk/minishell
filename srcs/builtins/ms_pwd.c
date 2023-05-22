
#include "builtins.h"
// #include "../../includes/builtins.h" // ? I need this on my mac

int	exec_pwd(t_data_exe *data_exe)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
	{
		perror("");
		data_exe->last_pid = errno;
		exit(errno);
	}
	else
		ft_putendl_fd(str, STDOUT_FILENO);
	free(str);
	data_exe->last_pid = 0;
	return (EXIT_SUCCESS);
}
