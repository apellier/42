/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:18:35 by apellier          #+#    #+#             */
/*   Updated: 2023/04/07 14:38:50 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	ret;
	int	i;

	if (!s)
		return (0);
	ret = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			ret++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ret);
}

static char	*splitdup(char const *s, int start, int end)
{
	char	*ret;
	int		i;
	int		len;

	len = end - start;
	ret = malloc (sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = 0;
	return (ret);
}

static int	free_split(char **ret, int i)
{
	while (i >= 0)
	{
		free(ret[i]);
		i--;
	}
	free(ret);
	return (0);
}

static int	do_split(char **ret, char const *s, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			k++;
		}
		if (k > 0)
		{
			ret[j++] = splitdup(s, i - k, i);
			if (!ret[j - 1])
				return (free_split(ret, j - 2));
		}
	}
	ret[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	if (!do_split(ret, s, c))
		return (NULL);
	return (ret);
}
