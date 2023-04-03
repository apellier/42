#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	// set errno to indicate the casuse of the error. ENOMEM : Insufficient memory available to allocate duplicate strings.
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}