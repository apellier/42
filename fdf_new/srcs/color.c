/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:19:17 by apellier          #+#    #+#             */
/*   Updated: 2023/10/25 18:21:46 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_minmax(t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			if (mapdata->points[i][j]->z > mapdata->transform->max_z)
				mapdata->transform->max_z = mapdata->points[i][j]->z;
			else if (mapdata->points[i][j]->z < mapdata->transform->min_z)
				mapdata->transform->min_z = mapdata->points[i][j]->z;
			j++;
		}
		i++;
	}
}

int	interpolate_color(int start, int end, double fraction)
{
	int	red;
	int	green;
	int	blue;

	red = (1 - fraction) * ((start >> 16) & 0xFF)
		+ fraction * ((end >> 16) & 0xFF);
	green = (1 - fraction) * ((start >> 8) & 0xFF)
		+ fraction * ((end >> 8) & 0xFF);
	blue = (1 - fraction) * (start & 0xFF)
		+ fraction * (end & 0xFF);
	return ((red << 16) | (green << 8) | blue);
}

void	set_color(t_mapdata *mapdata)
{
	int		i;
	int		j;
	double	fraction;

	find_minmax(mapdata);
	i = 0;
	if (mapdata->transform->max_z - mapdata->transform->min_z == 0)
		return ;
	while (i < mapdata->row)
	{
		j = 0;
		while (j < mapdata->column)
		{
			fraction = (mapdata->points[i][j]->z - mapdata->transform->min_z)
				/ (mapdata->transform->max_z - mapdata->transform->min_z);
			mapdata->points[i][j]->color
				= interpolate_color(MIN_COLOR, MAX_COLOR, fraction);
			j++;
		}
		i++;
	}
}
