#include "../includes/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (join);	
}