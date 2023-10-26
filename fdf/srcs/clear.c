/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:45:26 by apellier          #+#    #+#             */
/*   Updated: 2023/10/26 18:24:52 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mapdata(t_mapdata *mapdata)
{
	int	i;
	int	j;

	ft_secure_free((void **)&mapdata->transform);
	if (mapdata->window.win)
		mlx_destroy_window(mapdata->window.mlx, mapdata->window.win);
	if (mapdata->img.addr)
		mlx_destroy_image(mapdata->window.mlx, mapdata->img.img);
	i = 0;
	if (mapdata->points)
	{
		while (i < mapdata->row)
		{
			j = 0;
			while (j < mapdata->column)
			{
				ft_secure_free((void **)&(mapdata->points[i][j]));
				j++;
			}
			ft_secure_free((void **)&(mapdata->points[i]));
			i++;
		}
		ft_secure_free((void **)&(mapdata->points));
	}
	free(mapdata);
}

void	free_double_char(char **container)
{
	int	i;

	i = 0;
	while (container[i])
	{
		ft_secure_free((void **)&container[i]);
		i++;
	}
	ft_secure_free((void **)&container);
}
