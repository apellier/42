/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:17:14 by apellier          #+#    #+#             */
/*   Updated: 2023/04/07 14:24:18 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (size && count > 2147483647 / size)
		return (NULL);
	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_memset(result, 0, count * size);
	return (result);
}
