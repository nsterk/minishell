
#include "utils.h"

int	ft_strcheck(char const *s, int (*f)(int))
{
	int	i;

	if (!s || !f)
		return (EXIT_FAILURE);
	i = 0;
	while (s[i])
	{
		if (!f(s[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
