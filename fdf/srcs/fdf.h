/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:39:05 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 18:11:40 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

# include <mlx.h>
# include <math.h>
# include "../includes/libft/libft.h"
# include "../includes/libft/get_next_line/get_next_line.h"
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point {
    double  x;
    double  y;
    double  z;
    int     color;
}	t_point;

typedef struct s_imgData {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgdata;

typedef struct s_win {
    void *mlx;
    void *win;
}   t_win;

typedef struct s_mapdata {
    t_point ***points;
    t_imgdata   img;
    t_win   window;
    int     row;
    int     column;
    double  x_offset;
    double  y_offset;
    double  x_rotate;
    double  y_rotate;
    double  z_rotate;
    double  zoom_factor;
    double  x_center;
    double  y_center;
    double  z_center;
}   t_mapdata;

t_mapdata	*init_structure (void);
int			parsing(int argc, char **argv, t_mapdata *mapdata);
void		isometric_transform(t_mapdata *mapdata);
void	draw(t_mapdata *mapdata);
t_win	create_window(void);
t_imgdata	create_image(t_win *window);
void	close_window (t_win *window);
void	listener(t_win *window, t_mapdata *mapdata);
void	project(t_point *point, t_mapdata *mapdata);
void	update_image(t_mapdata *mapdata);
void	transform(t_mapdata *mapdata);
void	find_centers(t_mapdata *mapdata);
int	    ft_atoi_base(const char *str, int base);
