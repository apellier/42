/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:44:33 by apellier          #+#    #+#             */
/*   Updated: 2023/10/25 18:46:43 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_value(char **map, t_mapdata *mapdata)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (!ft_isdigit(map[i][j]) && (map[i][j] != '-' && map [i][j] != ' '
				&& map[i][j] != ',') && !(map[i][j] == 'x' ||
					(ft_toupper(map[i][j]) >= 'A'
						&& ft_toupper(map[i][j]) <= 'F')))
				return (1);
			j++;
		}
		i++;
	}
	mapdata->row = i;
	return (0);
}

int	check_column(char **map, t_mapdata *mapdata)
{
	int		i;
	int		j;
	char	**row;

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
			{
				free_double_char(row);
				return (1);
			}
		}
		free_double_char(row);
		i++;
	}
	return (0);
}
