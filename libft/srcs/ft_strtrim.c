#include "../includes/libft.h"

int	to_trim(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim (char const *s1, char const *set)
{
	int		i;
	char	result;

	i = 0;
}

/*
Parameters #1. The string to be trimmed.
#2. The reference set of characters to trim.

Return value The trimmed string. NULL if the allocation fails.

Description Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/