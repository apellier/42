/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:18:14 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 16:40:53 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!n)
		return (NULL);
	if (c > 256)
		c = c - 256;
	while (i <= n - 1)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
