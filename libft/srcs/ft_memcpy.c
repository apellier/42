#include "../includes/libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_mem;
	const char	*src_mem;

	i = 0;
	dest_mem = dest;
	src_mem = src;
	while (i < n && src_mem[i])
	{
		dest_mem[i] = src_mem[i];
		i++;
	}
	dest_mem[i] = 0;
	dest = dest_mem;
	return (dest);
}