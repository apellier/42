/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:17:41 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 15:32:17 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0 || n == 0)
		len ++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	get_result(int n, int i, char *result)
{
	while (n != 0)
	{
		result[--i] = n % 10 + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	i = get_len(n);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = 0;
	if (n < 0)
	{
		result[0] = '-';
		if (n == -2147483648)
		{
			result[--i] = '8';
			n = -214748364;
		}
		n *= -1;
	}
	if (n == 0)
		result[--i] = '0';
	else
		get_result(n, i, result);
	return (result);
}
