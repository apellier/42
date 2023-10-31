/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:58:48 by apellier          #+#    #+#             */
/*   Updated: 2023/10/25 19:58:40 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_on_points(t_point *point, t_transform *transform)
{
	point->x = (point->x - transform->x_center)
		* transform->zoom_factor + transform->x_center;
	point->y = (point->y - transform->y_center)
		* transform->zoom_factor + transform->y_center;
	point->z = (point->z - transform->z_center)
		* transform->zoom_factor + transform->z_center;
}

void	center_projection(t_mapdata	*mapdata)
{
	int	i;
	int	j;

	find_centers(mapdata);
	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->points[i][j]->x += WIDTH / 2
				- mapdata->transform->x_center;
			mapdata->points[i][j]->y += HEIGHT / 2
				- mapdata->transform->y_center;
			j++;
		}
		i++;
	}
}

void	isometric_transform(t_mapdata *mapdata)
{
	int		i;
	int		j;
	double	previous_x;
	double	previous_y;

	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			previous_x = mapdata->points[i][j]->x;
			previous_y = mapdata->points[i][j]->y;
			mapdata->points[i][j]->x = (previous_x - previous_y)
				* cos(0.523599);
			mapdata->points[i][j]->y = -1 * mapdata->points[i][j]->z
				+ (previous_x + previous_y) * sin(0.523599);
			j++;
		}
		i++;
	}
	center_projection(mapdata);
}

void	transform(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			project(mapdata->points[i][j], mapdata->transform);
			j++;
		}
		i++;
	}
	ft_bzero(&mapdata->transform->x_offset, sizeof(double));
	ft_bzero(&mapdata->transform->y_offset, sizeof(double));
	ft_bzero(&mapdata->transform->x_rotate, sizeof(double));
	ft_bzero(&mapdata->transform->y_rotate, sizeof(double));
	ft_bzero(&mapdata->transform->z_rotate, sizeof(double));
	ft_bzero(&mapdata->transform->zoom_factor, sizeof(double));
}

void	project(t_point *point, t_transform *transform)
{
	if (transform->x_offset)
		translate(point, transform->x_offset, 'x');
	else if (transform->y_offset)
		translate(point, transform->y_offset, 'y');
	if (transform->x_rotate)
		x_rotate(point, transform);
	else if (transform->y_rotate)
		y_rotate(point, transform);
	else if (transform->z_rotate)
		z_rotate(point, transform);
	if (transform->zoom_factor)
		zoom_on_points(point, transform);
}
