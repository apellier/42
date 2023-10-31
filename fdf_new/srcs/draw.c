/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:40:52 by apellier          #+#    #+#             */
/*   Updated: 2023/10/26 19:10:39 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	putpxl(int x, int y, int color, t_imgdata *img)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	putline(t_point *pointA, t_point *pointB, t_imgdata *img)
{
	t_linedata	linedata;
	int			e2;

	linedata = setup_linedata(pointA, pointB);
	while (1)
	{
		putpxl(linedata.x, linedata.y, interpolate_color(pointA->color,
				pointB->color, find_fraction(linedata, pointA, pointB)), img);
		if (linedata.x == (int)round(pointB->x)
			&& linedata.y == (int)round(pointB->y))
			break ;
		e2 = linedata.err;
		if (e2 > -linedata.dx)
		{
			linedata.err -= linedata.dy;
			linedata.x += linedata.sx;
		}
		if (e2 < linedata.dy)
		{
			linedata.err += linedata.dx;
			linedata.y += linedata.sy;
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
	ft_bzero(&mapdata->transform->x_center, sizeof(double));
	ft_bzero(&mapdata->transform->y_center, sizeof(double));
	ft_bzero(&mapdata->transform->z_center, sizeof(double));
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->transform->x_center += mapdata->points[i][j]->x;
			mapdata->transform->y_center += mapdata->points[i][j]->y;
			mapdata->transform->z_center += mapdata->points[i][j]->z;
			j++;
		}
		i++;
	}
	mapdata->transform->x_center /= mapdata->row * mapdata->column;
	mapdata->transform->y_center /= mapdata->row * mapdata->column;
	mapdata->transform->z_center /= mapdata->row * mapdata->column;
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
				putline(mapdata->points[i][j],
					mapdata->points[i][j + 1], &(mapdata->img));
			if (i + 1 < mapdata->row)
				putline(mapdata->points[i][j],
					mapdata->points[i + 1][j], &(mapdata->img));
			j++;
		}
		i++;
	}
	find_centers(mapdata);
	mlx_put_image_to_window
		(mapdata->window.mlx, mapdata->window.win, mapdata->img.img, 0, 0);
}
