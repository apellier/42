/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:38:39 by apellier          #+#    #+#             */
/*   Updated: 2023/10/26 19:17:53 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mapdata	*mapdata;

	mapdata = init_structure();
	if (!mapdata)
		return (1);
	if (parsing(argc, argv, mapdata))
	{
		free_mapdata(mapdata);
		return (1);
	}
	isometric_transform(mapdata);
	draw(mapdata);
	listener(&mapdata->window, mapdata);
	mlx_loop(mapdata->window.mlx);
	return (0);
}
