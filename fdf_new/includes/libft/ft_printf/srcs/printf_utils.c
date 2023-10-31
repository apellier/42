/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:06:34 by apellier          #+#    #+#             */
/*   Updated: 2023/04/18 12:34:51 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		count += ft_putchar(c);
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_putuns(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n < 10)
	{
		c = n + '0';
		count += ft_putchar(c);
	}
	else
	{
		count += ft_putuns(n / 10);
		count += ft_putuns(n % 10);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
