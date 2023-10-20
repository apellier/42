/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:08:53 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 20:23:37 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_events(int keycode, t_mapdata *mapdata)
{
	printf("keycode %d\n", keycode);
	if (keycode == 53)
		close_window(&mapdata->window);
	else if (keycode == 13)
		mapdata->y_offset = -0.01 * HEIGHT;
	else if (keycode == 0)
		mapdata->x_offset = -0.01 * WIDTH;
	else if (keycode == 1)
		mapdata->y_offset = 0.01 * HEIGHT;
	else if (keycode == 2)
		mapdata->x_offset = 0.01 * WIDTH;
	else if (keycode == 12)
		mapdata->x_rotate = -5;
	else if (keycode == 14)
		mapdata->x_rotate = 5;
	else if (keycode == 15)
		mapdata->y_rotate = -5;
	else if (keycode == 3)
		mapdata->y_rotate = 5;
	else if (keycode == 6)
		mapdata->z_rotate = -5;
	else if (keycode == 7)
		mapdata->z_rotate = 5;
	else if (keycode == 126)
		mapdata->zoom_factor = 1.1;
	else if (keycode == 125)
		mapdata->zoom_factor = 0.9;
	if (mapdata->zoom_factor || mapdata->x_offset || mapdata->y_offset || mapdata->x_rotate || mapdata->y_rotate || mapdata->z_rotate)
	{
		transform(mapdata);
		draw(mapdata);
	}
	return (keycode);
}

int	mouse_events(int button, int x, int y, t_mapdata *mapdata)
{
	if (button == 4)
		mapdata->zoom_factor = 0.9;
	else if (button == 5)
		mapdata->zoom_factor = 1.1;
	if (mapdata->zoom_factor)
	{
		transform(mapdata);
		draw(mapdata);
	}
	return (x + y);
}

int	red_cross(t_win *window)
{
	close_window(window);
	return (17);
}

void	listener(t_win *window, t_mapdata *mapdata)
{
	mlx_hook(window->win, 2, 0, key_events, mapdata);
	mlx_hook(window->win, 4, 0, mouse_events, mapdata);
	mlx_hook(window->win, 17, 0, red_cross, window);
}
