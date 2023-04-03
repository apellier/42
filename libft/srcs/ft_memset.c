#include "../includes/libft.h"

void	*memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*s_mem;

	s_mem = s;
	i = 0;
	while (i < n)
	{
		s_mem[i] = c;
		i++;
	}
	s = s_mem;
	return (s);
}