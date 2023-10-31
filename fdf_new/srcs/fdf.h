/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:39:05 by apellier          #+#    #+#             */
/*   Updated: 2023/10/30 21:17:12 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../includes/libft/libft.h"
# include "../includes/libft/get_next_line/get_next_line.h"
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MIN_COLOR 0xFFF588
# define MAX_COLOR 0x521A9E

typedef struct s_point {
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_imgData {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgdata;

typedef struct s_win {
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_transform {
	double	x_offset;
	double	y_offset;
	double	x_rotate;
	double	y_rotate;
	double	z_rotate;
	double	zoom_factor;
	double	x_center;
	double	y_center;
	double	z_center;
	double	max_z;
	double	min_z;
}	t_transform;

typedef struct s_mapdata {
	t_point		***points;
	t_imgdata	img;
	t_win		window;
	t_transform	*transform;
	int			row;
	int			column;
	int			has_color;
	int			map_scale;
}	t_mapdata;

typedef struct s_linedata {
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	err;
	int	sx;
	int	sy;
}	t_linedata;

t_mapdata	*init_structure(void);
int			parsing(int argc, char **argv, t_mapdata *mapdata);
void		isometric_transform(t_mapdata *mapdata);
void		draw(t_mapdata *mapdata);
t_win		create_window(void);
t_imgdata	create_image(t_win *window);
void		close_window(t_mapdata *mapdata);
void		listener(t_win *window, t_mapdata *mapdata);
void		project(t_point *point, t_transform *transform);
void		update_image(t_mapdata *mapdata);
void		transform(t_mapdata *mapdata);
void		find_centers(t_mapdata *mapdata);
int			ft_atoi_base(const char *str, int base);
void		free_mapdata(t_mapdata *mapdata);
void		free_double_char(char **container);
void		set_color(t_mapdata *mapdata);
int			interpolate_color(int start, int end, double fraction);
int			check_value(char **map, t_mapdata *mapdata);
int			check_column(char **map, t_mapdata *mapdata);
void		z_rotate(t_point *point, t_transform *transform);
void		y_rotate(t_point *point, t_transform *transform);
void		x_rotate(t_point *point, t_transform *transform);
void		translate(t_point *point, double offset, char axis);
t_linedata	setup_linedata(t_point *pointA, t_point *pointB);
double		find_fraction(t_linedata linedata,
				t_point *pointA, t_point *pointB);

#endif