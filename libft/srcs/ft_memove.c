#include "../includes/libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	char		tmp[n + 1];
	char		*dest_mem;
	const char	*src_mem;
	size_t		i;

	i = 0;
	dest_mem = dest;
	src_mem = src;
	while (i < n && src_mem[i])
	{
		tmp[i] = src_mem[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_mem[i] = tmp[i];
		i++;
	}
	dest_mem[i] = 0;
	dest = dest_mem;
	return (dest);
}