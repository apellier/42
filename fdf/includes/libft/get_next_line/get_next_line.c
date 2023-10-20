/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:44:36 by apellier          #+#    #+#             */
/*   Updated: 2023/10/13 18:26:26 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char buffer[], int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read && buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	make_line(char **line, char (*buffer)[], int bytes_read, int nl_pos)
{
	int		line_found;

	line_found = 0;
	if (nl_pos == -1)
	{
		*line = join_lines(*line, *buffer, bytes_read);
		empty_buffer(buffer, bytes_read);
		if (bytes_read < BUFFER_SIZE)
			line_found = 1;
	}
	else
	{
		*line = join_lines(*line, *buffer, nl_pos);
		rm_elem_from_buffer(buffer, nl_pos + 1);
		line_found = 1;
	}
	return (line_found);
}

int	fill_buffer(int fd, int *bytes_read, char **line, char (*buffer)[])
{
	*bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (*bytes_read < 0 && (*line)[0])
		free (*line);
	if (*bytes_read < 0 || (*bytes_read == 0 && !(*line)[0]))
		return (0);
	(*buffer)[*bytes_read] = 0;
	return (1);
}

macron demission
allo

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			line_found;
	static int	bytes_read = 0;
	int			nl_pos;

	if (fd < 0)
		return (NULL);
	line_found = 0;
	line = "";
	while (line_found == 0)
	{
		if (!buffer[0] && !fill_buffer(fd, &bytes_read, &line, &buffer))
			return (NULL);
		nl_pos = check_nl(buffer, bytes_read);
		line_found = make_line(&line, &buffer, bytes_read, nl_pos);
		if (!line)
			return (NULL);
	}
	return (line);
}
