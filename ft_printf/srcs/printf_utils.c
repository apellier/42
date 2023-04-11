/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:06:34 by apellier          #+#    #+#             */
/*   Updated: 2023/04/11 17:01:46 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putchar(char c)
{
	static int	count = 0;

	write (1, &c, 1);
	count ++;
	return (count);
}

int	ft_putnbr_hexa(unsigned long long nbr, int lcase)
{
	char	*base_hexa_lower;
	char	*base_hexa_upper;
	int		count;

	base_hexa_lower = "0123456789abcdef";
	base_hexa_upper = "0123456789ABCDEF";
/* 	if (nbr < 0)
	{
		count = ft_putchar('-');
		nbr = -nbr;
	} */
	if (nbr < 16)
	{
		if (lcase == 0)
			count = ft_putchar(base_hexa_lower[nbr]);
		if (lcase == 1)
			count = ft_putchar(base_hexa_upper[nbr]);
	}
	else
	{
		count = ft_putnbr_hexa(nbr / 16, lcase);
		count = ft_putnbr_hexa(nbr % 16, lcase);
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	if (n == -2147483648)
	{
		count = ft_putchar('-');
		count = ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count = ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		count = ft_putchar(c);
	}
	else
	{
		count = ft_putnbr(n / 10);
		count = ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	while (s[i])
	{
		count = ft_putchar(s[i]);
		i++;
	}
	return (count);
}
