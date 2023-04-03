#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unisgned int, char *))
{
	int	i;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}