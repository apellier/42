/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:48 by apellier          #+#    #+#             */
/*   Updated: 2023/10/26 19:17:42 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_transform(t_transform *transform)
{
	ft_bzero(&transform->x_offset, sizeof(double));
	ft_bzero(&transform->y_offset, sizeof(double));
	ft_bzero(&transform->x_rotate, sizeof(double));
	ft_bzero(&transform->y_rotate, sizeof(double));
	ft_bzero(&transform->z_rotate, sizeof(double));
	ft_bzero(&transform->zoom_factor, sizeof(double));
	ft_bzero(&transform->x_center, sizeof(double));
	ft_bzero(&transform->y_center, sizeof(double));
	ft_bzero(&transform->z_center, sizeof(double));
	ft_bzero(&transform->min_z, sizeof(double));
	ft_bzero(&transform->max_z, sizeof(double));
}

t_mapdata	*init_structure(void)
{
	t_mapdata	*mapdata;

	mapdata = malloc(sizeof(t_mapdata));
	if (!mapdata)
		return (NULL);
	mapdata->transform = malloc(sizeof(t_transform));
	if (!mapdata->transform)
		return (NULL);
	init_transform(mapdata->transform);
	mapdata->points = NULL;
	ft_bzero(&mapdata->row, sizeof(int));
	ft_bzero(&mapdata->column, sizeof(int));
	ft_bzero(&mapdata->has_color, sizeof(int));
	mapdata->window = create_window();
	mapdata->img = create_image (&mapdata->window);
	return (mapdata);
}

int	ft_isdigit_base(char c, int base)
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

int	ft_atoi_base(const char *str, int base)
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
	{
		if (str[i++] == '-')
			sign = -1;
		else
			sign = 1;
	}
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}
