/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:05:39 by apellier          #+#    #+#             */
/*   Updated: 2023/10/20 20:32:02 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_value(char **map, t_mapdata *mapdata)
{
	//free
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[j])
        {
            if (!ft_isdigit(map[i][j]) && map[i][j] != '-' && map [i][j] != ' ' && !(map[i][j] == 'x' || (map[i][j] >= 'A' && map[i][j] <= 'F')))
                return (1); 
            j++;
        }
        i++;
    }
    mapdata->row = i;
    return (0);
}

int check_column(char **map, t_mapdata *mapdata)
{
	// free
    int     i;
    int     j;
    char    **row;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        row = ft_split(map[i], ' ');
        while (row[j])
            j++;
        if (!mapdata->column)
            mapdata->column = j;
        else
        {
            if (j != mapdata->column)
                return (1);
        }
        i++;
    }
    return (0);
}

char	**get_map_from_file(int fd)
{
	// free
	char	*line;
	char	*tmp;

	line = "";
	tmp = get_next_line(fd);
	while (tmp)
	{
		line = ft_strjoin(line, tmp);
		tmp = get_next_line(fd);
	}
	return (ft_split(line, '\n'));
}

void	setpoint(char **sourcemap, t_mapdata *mapdata, int i, int j)
{
	//free
	char	**line;

	mapdata->points[i][j]->x = j * 30;
	mapdata->points[i][j]->y = i * 30;
	line = ft_split(sourcemap[i], ' ');
	mapdata->points[i][j]->z = (double)ft_atoi(line[j]) * 3;
	if (ft_strchr(line[j], ','))
		mapdata->points[i][j]->color = ft_atoi_base(ft_strchr(line[j], ','), 16);
	else
		mapdata->points[i][j]->color = 0xFFFFFFFF;
	free(line);
}

int	init_map(char **sourcemap, t_mapdata *mapdata)
{
	// free
	int	i;
	int	j;

	mapdata->points = malloc(sizeof(t_point	**) * mapdata->row);
	if (!mapdata->points)
		return (1);
	i = 0;
	while (i < mapdata->row)
	{
		mapdata->points[i] = malloc(sizeof(t_point *) * mapdata->column);
		if (!mapdata->points[i])
			return (1);
			//free structure
		j = 0;
		while (j < mapdata->column)
		{
			mapdata->points[i][j] = malloc(sizeof(t_point));
			if (!mapdata->points[i][j])
				return (1);
				//free structure
			setpoint(sourcemap, mapdata, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
int	parsing(int argc, char **argv, t_mapdata *mapdata)
{
	// free
	int		fd;
	char	**map;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (1);
	map = get_map_from_file(fd);
	if (check_value(map, mapdata) || check_column(map, mapdata))
		return (1);
	if (init_map(map, mapdata))
		return (1);
	return (0);
}
