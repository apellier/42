/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:48 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 18:14:58 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mapdata	*init_structure(void)
{
	t_mapdata	*mapdata;

	mapdata = malloc(sizeof(t_mapdata));
	if (!mapdata)
		return (NULL);
	ft_bzero(&mapdata->row, sizeof(int));
	ft_bzero(&mapdata->column, sizeof(int));
	ft_bzero(&mapdata->x_offset, sizeof(double));
	ft_bzero(&mapdata->y_offset, sizeof(double));
	ft_bzero(&mapdata->x_rotate, sizeof(double));
	ft_bzero(&mapdata->y_rotate, sizeof(double));
	ft_bzero(&mapdata->z_rotate, sizeof(double));
	ft_bzero(&mapdata->zoom_factor, sizeof(double));
	ft_bzero(&mapdata->x_center, sizeof(double));
	ft_bzero(&mapdata->y_center, sizeof(double));
	ft_bzero(&mapdata->z_center, sizeof(double));
	mapdata->window = create_window(); // free window
	mapdata->img = create_image (&mapdata->window); // free img
	return (mapdata);
}
static int		ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}
int	ft_has_prefix(const char *str, int base)
{
	size_t	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (1);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}

int				ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}
