/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:10:55 by apellier          #+#    #+#             */
/*   Updated: 2023/10/26 19:13:01 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_linedata	setup_linedata(t_point *pointA, t_point *pointB)
{
	t_linedata	linedata;

	linedata.x = (int)round(pointA->x);
	linedata.y = (int)round(pointA->y);
	linedata.dx = abs((int)round(pointB->x) - linedata.x);
	linedata.dy = abs((int)round(pointB->y) - linedata.y);
	if (pointA->x < pointB->x)
		linedata.sx = 1;
	else
		linedata.sx = -1;
	if (pointA->y < pointB->y)
		linedata.sy = 1;
	else
		linedata.sy = -1;
	if (linedata.dx > linedata.dy)
		linedata.err = linedata.dx / 2;
	else
		linedata.err = -linedata.dy / 2;
	return (linedata);
}

double	find_fraction(t_linedata linedata, t_point *pointA, t_point *pointB)
{
	double	fraction;

	fraction = sqrt(pow(linedata.x - pointA->x, 2)
			+ pow(linedata.y - pointA->y, 2))
		/ sqrt(pow(pointB->x - pointA->x, 2)
			+ pow(pointB->y - pointA->y, 2));
	return (fraction);
}
