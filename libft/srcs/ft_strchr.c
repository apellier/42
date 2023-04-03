#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)s;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (result + i);
		i++;
	}
	if (s[i] == c)
		return (result + i);
	return (NULL);
}