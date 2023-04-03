#include "../includes/libft.h"

int	is_sep(char const src, char sep)
{
	if (src == sep)
		return (1);
	return (0);
}

int	count_words(char const *s, char c)
{
	int	wd_count;
	int	i;

	wd_count = 0;
	i = 0;
	while (s[i])
	{
		if ((is_sep(s[i - 1]) || i == 0) && !(is_sep(s[i])))
			wd_count++;
		i++;
	}
	return (wd_count)
}

int	get_len(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] || s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = malloc(sizeof(char *) * count_words(s, c)) // is the array finishing by a 0 ?
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((is_sep(s[i - 1]) || i == 0) && !(is_sep(s[i])))
		{
			result[j] == ft_strdup(ft_strst)
			j++,
		}

	}
	
}