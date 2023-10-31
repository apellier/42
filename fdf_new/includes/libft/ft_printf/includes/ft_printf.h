/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:40:25 by apellier          #+#    #+#             */
/*   Updated: 2023/04/18 12:34:27 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h>

int	ft_putpoint_hexa(unsigned long nbr, int lcase);
int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putuns(unsigned int n);
int	ft_putnbr_hexa(unsigned int nbr, int lcase);

#endif