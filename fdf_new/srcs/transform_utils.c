/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:47:19 by apellier          #+#    #+#             */
/*   Updated: 2023/10/25 18:48:52 by apellier         ###   ########.fr       */
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

void	x_rotate(t_point *point, t_transform *transform)
{
	double	previous_y;
	double	previous_z;
	double	new_y;
	double	new_z;

	previous_y = point->y - transform->y_center;
	previous_z = point->z - transform->z_center;
	new_y = previous_y * cos(transform->x_rotate * M_PI / 180)
		- previous_z * sin(transform->x_rotate * M_PI / 180);
	new_z = previous_y * sin(transform->x_rotate * M_PI / 180)
		+ previous_z * cos(transform->x_rotate * M_PI / 180);
	point->y = new_y + transform->y_center;
	point->z = new_z + transform->z_center;
}

void	y_rotate(t_point *point, t_transform *transform)
{
	double	previous_x;
	double	previous_z;
	double	new_x;
	double	new_z;

	previous_x = point->x - transform->x_center;
	previous_z = point->z - transform->z_center;
	new_x = previous_x * cos(transform->y_rotate * M_PI / 180)
		+ previous_z * sin(transform->y_rotate * M_PI / 180);
	new_z = -previous_x * sin(transform->y_rotate * M_PI / 180)
		+ previous_z * cos(transform->y_rotate * M_PI / 180);
	point->x = new_x + transform->x_center;
	point->z = new_z + transform->z_center;
}

void	z_rotate(t_point *point, t_transform *transform)
{
	double	previous_x;
	double	previous_y;
	double	new_x;
	double	new_y;

	previous_x = point->x - transform->x_center;
	previous_y = point->y - transform->y_center;
	new_x = previous_x * cos(transform->z_rotate * M_PI / 180)
		- previous_y * sin(transform->z_rotate * M_PI / 180);
	new_y = previous_x * sin(transform->z_rotate * M_PI / 180)
		+ previous_y * cos(transform->z_rotate * M_PI / 180);
	point->x = new_x + transform->x_center;
	point->y = new_y + transform->y_center;
}
