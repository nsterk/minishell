
#include "utils.h"

void	check_malloc(void *ptr, char *func)
{
	if (!ptr)
	{
		errno = ENOMEM;
		exit_error(errno, func, NULL);
	}
	return ;
}
