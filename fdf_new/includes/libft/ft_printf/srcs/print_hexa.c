/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:43:54 by apellier          #+#    #+#             */
/*   Updated: 2023/04/18 12:35:06 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putpoint_hexa(unsigned long nbr, int lcase)
{
	char	*base_hexa_lower;
	char	*base_hexa_upper;
	int		count;

	count = 0;
	base_hexa_lower = "0123456789abcdef";
	base_hexa_upper = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (lcase == 0)
			ft_putchar(base_hexa_lower[nbr]);
		if (lcase == 1)
			ft_putchar(base_hexa_upper[nbr]);
		count++;
	}
	else
	{
		count += ft_putpoint_hexa(nbr / 16, lcase);
		count += ft_putpoint_hexa(nbr % 16, lcase);
	}
	return (count);
}

int	ft_putnbr_hexa(unsigned int nbr, int lcase)
{
	char	*base_hexa_lower;
	char	*base_hexa_upper;
	int		count;

	count = 0;
	base_hexa_lower = "0123456789abcdef";
	base_hexa_upper = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (lcase == 0)
			ft_putchar(base_hexa_lower[nbr]);
		if (lcase == 1)
			ft_putchar(base_hexa_upper[nbr]);
		count++;
	}
	else
	{
		count += ft_putnbr_hexa(nbr / 16, lcase);
		count += ft_putnbr_hexa(nbr % 16, lcase);
	}
	return (count);
}
