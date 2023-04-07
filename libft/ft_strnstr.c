/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:19:02 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 14:35:08 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	size_t	haystack_len;

	i = 0;
	if (!len && !haystack)
		return (NULL);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (!needle[i])
		return ((char *) haystack);
	if (needle_len > haystack_len)
		return (NULL);
	while (haystack[i] && i + needle_len <= len)
	{
		if (!ft_strncmp(haystack + i, needle, needle_len))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
