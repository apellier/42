/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:40:19 by apellier          #+#    #+#             */
/*   Updated: 2023/04/13 15:44:41 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	disp_printf(const char *input, int i, va_list arglist)
{
	int	count;

	count = 0;
	if (input[i + 1] == 'c')
		count += ft_putchar((char)va_arg(arglist, int));
	if (input[i + 1] == 's')
		count += ft_putstr(va_arg(arglist, char *));
	if (input[i + 1] == 'p')
		count += ft_putstr("0x")
			+ ft_putpoint_hexa(va_arg(arglist, unsigned long), 0);
	if (input[i + 1] == 'd' || input[i + 1] == 'i')
		count += ft_putnbr(va_arg(arglist, int));
	if (input[i + 1] == 'u')
		count += ft_putuns(va_arg(arglist, unsigned int));
	if (input[i + 1] == 'x')
		count += ft_putnbr_hexa(va_arg(arglist, int), 0);
	if (input[i + 1] == 'X')
		count += ft_putnbr_hexa(va_arg(arglist, int), 1);
	if (input[i + 1] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	arglist;
	int		i;
	int		count;

	va_start(arglist, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += disp_printf(input, i, arglist);
			i++;
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	va_end(arglist);
	return (count);
}
