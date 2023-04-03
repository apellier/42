#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	
	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		write (fd, ct, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}