
#include "utils.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}