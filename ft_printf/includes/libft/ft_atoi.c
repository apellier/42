/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:17:04 by apellier          #+#    #+#             */
/*   Updated: 2023/04/06 17:34:26 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	long	check;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr && nptr[i] >= '0' && nptr[i] <= '9')
	{
		check = result;
		result = result * 10 + nptr[i] - 48;
		if ((result ^ check) < 0)
			return ((sign + 1) / -2);
		i++;
	}
	return (result * sign);
}
