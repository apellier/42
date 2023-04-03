#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	while (n != 0)
		{
			i++;
			n = n / 10;
		}
	if (n < 0)
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		result[i] == n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (result);
}
