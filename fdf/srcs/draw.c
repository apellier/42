/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:40:52 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 20:23:11 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpxl(int x, int y, int color, t_imgdata *img)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * 
				(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	putline(t_point *pointA, t_point *pointB, t_imgdata *img)
{
	double	x;
	double	y;
	double	err;

	x = pointA->x;
	y = pointA->y;
	err = fabs(pointB->x - pointA->x) - fabs(pointB->y - pointA->y);
	while (1)
	{
		putpxl(x, y, pointA->color, img);
		if (fabs(x - pointB->x) < 0.5 && fabs(y - pointB->y) < 0.5)
			break ;
		if (2 * err > -1 * fabs(pointB->y - pointA->y))
		{
			err -= fabs(pointB->y - pointA->y);
			if (pointA->x < pointB->x)
				x += 0.5;
			else
				x -= 0.5;
		}
		if (2 * err < fabs(pointB->x - pointA->x))
		{
			err += fabs(pointB->x - pointA->x);
			if (pointA->y < pointB->y)
				y += 0.5;
			else
				y -= 0.5;
		}
	}
}

void	clear_image(t_imgdata *imgdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			putpxl(j, i, 0, imgdata);
			j++;
		}
		i++;
	}
}

void	find_centers(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->x_center += mapdata->points[i][j]->x;
			mapdata->y_center += mapdata->points[i][j]->y;
			mapdata->z_center += mapdata->points[i][j]->z;
			j++;
		}
		i++;
	}
	mapdata->x_center /= mapdata->row * mapdata->column;
	mapdata->y_center /= mapdata->row * mapdata->column;
	mapdata->z_center /= mapdata->row * mapdata->column;
}

void	draw(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	clear_image(&mapdata->img);
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			if (j + 1 < mapdata->column)
				putline(mapdata->points[i][j], mapdata->points[i][j + 1], &(mapdata->img));
			if (i + 1 < mapdata->row)
				putline(mapdata->points[i][j], mapdata->points[i + 1][j], &(mapdata->img));
			j++;
		}
		i++;
	}
	find_centers(mapdata);
	mlx_put_image_to_window(mapdata->window.mlx, mapdata->window.win, mapdata->img.img, 0, 0);
}
