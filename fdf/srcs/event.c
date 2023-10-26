/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:08:53 by apellier          #+#    #+#             */
/*   Updated: 2023/10/25 18:28:16 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_events(int keycode, t_mapdata *mapdata)
{
	if (keycode == 3)
		mapdata->transform->x_rotate = -5;
	else if (keycode == 15)
		mapdata->transform->x_rotate = 5;
	else if (keycode == 12)
		mapdata->transform->y_rotate = -5;
	else if (keycode == 14)
		mapdata->transform->y_rotate = 5;
	else if (keycode == 6)
		mapdata->transform->z_rotate = -5;
	else if (keycode == 7)
		mapdata->transform->z_rotate = 5;
	return (keycode);
}

int	key_events(int keycode, t_mapdata *mapdata)
{
	if (keycode == 53)
		close_window(mapdata);
	else if (keycode == 13)
		mapdata->transform->y_offset = -0.01 * HEIGHT;
	else if (keycode == 0)
		mapdata->transform->x_offset = -0.01 * WIDTH;
	else if (keycode == 1)
		mapdata->transform->y_offset = 0.01 * HEIGHT;
	else if (keycode == 2)
		mapdata->transform->x_offset = 0.01 * WIDTH;
	else if (keycode == 126)
		mapdata->transform->zoom_factor = 1.1;
	else if (keycode == 125)
		mapdata->transform->zoom_factor = 0.9;
	else
		rotate_events(keycode, mapdata);
	if (mapdata->transform->zoom_factor || mapdata->transform->x_offset
		|| mapdata->transform->y_offset || mapdata->transform->x_rotate
		|| mapdata->transform->y_rotate || mapdata->transform->z_rotate)
	{
		transform(mapdata);
		draw(mapdata);
	}
	return (keycode);
}

int	mouse_events(int button, int x, int y, t_mapdata *mapdata)
{
	if (button == 4)
		mapdata->transform->zoom_factor = 0.9;
	else if (button == 5)
		mapdata->transform->zoom_factor = 1.1;
	if (mapdata->transform->zoom_factor)
	{
		transform(mapdata);
		draw(mapdata);
	}
	return (x + y);
}

int	red_cross(t_mapdata *mapdata)
{
	close_window(mapdata);
	return (17);
}

void	listener(t_win *window, t_mapdata *mapdata)
{
	mlx_hook(window->win, 2, 0, key_events, mapdata);
	mlx_hook(window->win, 4, 0, mouse_events, mapdata);
	mlx_hook(window->win, 17, 0, red_cross, mapdata);
}
