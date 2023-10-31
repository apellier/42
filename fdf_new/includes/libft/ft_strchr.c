/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:18:37 by apellier          #+#    #+#             */
/*   Updated: 2023/04/12 12:31:16 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)s;
	while (c >= 256)
		c = c - 256;
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
