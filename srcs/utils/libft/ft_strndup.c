#include "utils.h"

char	*ft_strndup(char *src, size_t n)
{
	char	*str;

	str = malloc(sizeof(*str) * (n + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, n + 1);
	return (str);
}
