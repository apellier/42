/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:05:39 by apellier          #+#    #+#             */
/*   Updated: 2023/10/31 11:38:02 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_map_from_file(int fd)
{
	char	*line;
	char	*tmp;
	char	**map;

	line = "";
	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		ft_secure_free((void **)&tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	ft_secure_free((void **)&line);
	return (map);
}

void	setpoint(char **sourcemap, t_mapdata *mapdata, int i, int j)
{
	char	**line;

	if (mapdata->column * mapdata->row <= 100)
		mapdata->map_scale = 60;
	else if (mapdata->column * mapdata->row <= 1000)
		mapdata->map_scale = 30;
	else if (mapdata->column * mapdata->row <= 10000)
		mapdata->map_scale = 15;
	else if (mapdata->column * mapdata->row <= 100000)
		mapdata->map_scale = 6;
	else
		mapdata->map_scale = 3;
	mapdata->points[i][j]->x = j * mapdata->map_scale;
	mapdata->points[i][j]->y = i * mapdata->map_scale;
	line = ft_split(sourcemap[i], ' ');
	mapdata->points[i][j]->z = (double)ft_atoi(line[j])
		* (mapdata->map_scale / 3);
	if (ft_strchr(line[j], ','))
	{
		mapdata->points[i][j]->color
			= ft_atoi_base(ft_strchr(line[j], ',') + 1, 16);
		if (!mapdata->has_color)
			mapdata->has_color = 1;
	}
	ft_secure_free((void **)&line);
}

int	init_map(char **sourcemap, t_mapdata *mapdata)
{
	int	i;
	int	j;

	mapdata->points = malloc(sizeof(t_point **) * mapdata->row);
	if (!mapdata->points)
		return (1);
	i = 0;
	while (i < mapdata->row)
	{
		mapdata->points[i] = malloc(sizeof(t_point *) * mapdata->column);
		if (!mapdata->points[i])
			return (1);
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->points[i][j] = malloc(sizeof(t_point));
			if (!mapdata->points[i][j])
				return (1);
			setpoint(sourcemap, mapdata, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv, t_mapdata *mapdata)
{
	int		fd;
	char	**map;

	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".fdf", 4))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	map = get_map_from_file(fd);
	if (!map)
		return (1);
	if (check_value(map, mapdata) || check_column(map, mapdata))
	{
		free_double_char(map);
		return (1);
	}
	if (init_map(map, mapdata))
	{
		free_double_char(map);
		return (1);
	}
	if (!mapdata->has_color)
		set_color(mapdata);
	return (0);
}
