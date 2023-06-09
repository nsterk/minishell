
#include "utils.h"

char *ft_replace(char *dst, char *src, size_t start, size_t end)
{
	char	*front;
	char	*back;

	if (!dst)
		return (NULL);
	front = ft_substr(dst, 0, start);
	front = strjoin_free(front, src);
	back = ft_substr(dst, end + 1, ft_strlen(dst) - end);
	front = strjoin_free(front, back);
	free(dst);
	free(back);
	return (front);
}

// int	main(void)
// {
// 	char *test;
// 	char *env;

// 	test = ft_strndup("this$is$a$test", 14);
// 	env = ft_strndup("FLAP", 4);
// 	printf("%s\n", test);
// 	test = ft_replace(test, env, 4, 6);
// 	printf("%s\n", test);
// 	free(test);
// 	return (0);
// }