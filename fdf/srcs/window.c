/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:49:50 by apellier          #+#    #+#             */
/*   Updated: 2023/10/15 17:12:26 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_win	create_window(void)
{
	t_win	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "fdf");
	return (window);
}

void	close_window(t_win *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit (0);
}

t_imgdata	create_image(t_win *window)
{
	t_imgdata	img;

	img.img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	return (img);
}
