#include "../includes/libft.h"

void	bzero(void *s, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = s;
	while (i < n)
	{
		result[i] = 0;
		i++;
	}
}