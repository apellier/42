/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:58:48 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 17:24:46 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_point *point, double offset, char axis)
{
	if (axis == 'x')
		point->x += offset;

	else if (axis == 'y')
		point->y += offset;
	return ;
}

void x_rotate(t_point *point, t_mapdata *mapdata)
{
    double previous_y = point->y - mapdata->y_center;
    double previous_z = point->z - mapdata->z_center;
    
    // Calculate the new y and z values separately
    double new_y = previous_y * cos(mapdata->x_rotate * M_PI / 180) - previous_z * sin(mapdata->x_rotate * M_PI / 180);
    double new_z = previous_y * sin(mapdata->x_rotate * M_PI / 180) + previous_z * cos(mapdata->x_rotate * M_PI / 180);
    
    // Update the point's y and z with the new values
    point->y = new_y + mapdata->y_center;
    point->z = new_z + mapdata->z_center;
}

void y_rotate(t_point *point, t_mapdata *mapdata)
{
    double previous_x = point->x - mapdata->x_center;
    double previous_z = point->z - mapdata->z_center;
    
    // Calculate the new x and z values separately
    double new_x = previous_x * cos(mapdata->y_rotate * M_PI / 180) + previous_z * sin(mapdata->y_rotate * M_PI / 180);
    double new_z = -previous_x * sin(mapdata->y_rotate * M_PI / 180) + previous_z * cos(mapdata->y_rotate * M_PI / 180);
    
    // Update the point's x and z with the new values
    point->x = new_x + mapdata->x_center;
    point->z = new_z + mapdata->z_center;
}
void z_rotate(t_point *point, t_mapdata *mapdata)
{
    double previous_x = point->x - mapdata->x_center;
    double previous_y = point->y - mapdata->y_center;
    
    // Calculate the new x and y values separately
    double new_x = previous_x * cos(mapdata->z_rotate * M_PI / 180) - previous_y * sin(mapdata->z_rotate * M_PI / 180);
    double new_y = previous_x * sin(mapdata->z_rotate * M_PI / 180) + previous_y * cos(mapdata->z_rotate * M_PI / 180);

    // Update the point's x and y with the new values
    point->x = new_x + mapdata->x_center;
    point->y = new_y + mapdata->y_center;
}

void	zoom_on_points(t_point *point, t_mapdata *mapdata)
{
	point->x = (point->x - mapdata->x_center) * mapdata->zoom_factor + mapdata->x_center;    
	point->y = (point->y - mapdata->y_center) * mapdata->zoom_factor + mapdata->y_center;    
}

void	oblic_transform(t_mapdata *mapdata)
{
	int	i;
	int	j;
	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->points[i][j]->x = mapdata->points[i][j]->x + mapdata->points[i][j]->z * cos(0.785398);
			mapdata->points[i][j]->y = mapdata->points[i][j]->y + mapdata->points[i][j]->z * sin(0.785398);
			j++;
		}
		i++;
	}
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
			mapdata->points[i][j]->x += WIDTH/2 - mapdata->x_center;
			mapdata->points[i][j]->y += HEIGHT/2 - mapdata->y_center;
			j++;
		}
		i++;
	}	
}
void	isometric_transform(t_mapdata *mapdata)
{
	int	i;
	int	j;
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
				mapdata->points[i][j]->x = (previous_x - previous_y) * cos(0.523599);
				mapdata->points[i][j]->y = -1 * mapdata->points[i][j]->z + (previous_x + previous_y) * sin(0.523599);
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
			project(mapdata->points[i][j], mapdata);
			j++;
		}
		i++;
	}
	ft_bzero(&mapdata->x_offset, sizeof(double));
	ft_bzero(&mapdata->y_offset, sizeof(double));
	ft_bzero(&mapdata->x_rotate, sizeof(double));
	ft_bzero(&mapdata->y_rotate, sizeof(double));
	ft_bzero(&mapdata->z_rotate, sizeof(double));
	ft_bzero(&mapdata->zoom_factor, sizeof(double));
}

void	project(t_point *point, t_mapdata *mapdata)
{
	if (mapdata->x_offset)
		translate(point, mapdata->x_offset, 'x');
	else if (mapdata->y_offset)
		translate(point, mapdata->y_offset, 'y');
	if (mapdata->x_rotate)
		x_rotate(point, mapdata);
	else if (mapdata->y_rotate)
		y_rotate(point, mapdata);
	else if (mapdata->z_rotate)
		z_rotate(point, mapdata);
	if (mapdata->zoom_factor)
		zoom_on_points(point, mapdata);
}
