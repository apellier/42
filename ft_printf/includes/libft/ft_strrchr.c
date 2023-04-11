/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:19:05 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 16:26:27 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*source;

	i = ft_strlen(s) + 1;
	source = (char *)s;
	if (c > 256)
		c = c - 256;
	while (i > 0)
	{
		i--;
		if (source[i] == c)
			return (source + i);
	}
	if (source[i] == c)
		return (source + i);
	return (NULL);
}
