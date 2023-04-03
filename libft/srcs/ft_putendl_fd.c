#include "../includes/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd == -1)
		return;
	ft_putstr_fd(s, fd);
	write(fd, '\n', 1);
}