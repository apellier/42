/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:19:07 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 15:37:01 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_length(char const *s1, char const *set)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = ft_strlen(s1) - 1;
	while (is_set(s1[ret], set))
	{
		if (ret == 0)
			return (0);
		ret--;
	}
	while (is_set(s1[i], set))
	{
		ret--;
		i++;
	}
	return (ret + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	ret_len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	ret_len = get_length(s1, set);
	ret = malloc(sizeof(char) * (ret_len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (is_set(s1[i], set))
		i++;
	while (j < ret_len)
	{
		ret[j] = s1[i];
		j++;
		i++;
	}
	ret[j] = 0;
	return (ret);
}
