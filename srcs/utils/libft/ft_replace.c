
#include "utils.h"

/**
 * @brief 
 * 
 * @param dst 
 * @param src 
 * @param start 
 * @param end 
 * @return char* 
 */
char *ft_replace(char *dst, char *src, size_t start, size_t end)
{
	char	*front;
	char	*back;

	if (!dst)
		return (NULL);
	front = ft_substr(dst, 0, start);
	if (src)
		front = strjoin_free(front, src);
	back = ft_substr(dst, end + 1, ft_strlen(dst) - end);
	front = strjoin_free(front, back);
	free(dst);
	return (front);
}
