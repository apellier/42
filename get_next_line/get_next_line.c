/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:14:07 by apellier          #+#    #+#             */
/*   Updated: 2023/04/11 09:27:01 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE];
	static ssize_t	nb_read;
	static ssize_t	i = 0;
	
	if (fd == -1) // or < 0 ?
		return (NULL);
	nb_read = -1;
	line = malloc(sizeof(char) * 43);
	while (nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (NULL);
		while (i < nb_read && buf[i] && buf[i] != '\n')
		{
			line[i] = buf[i];
			i++;
		}
		line[i++] = '\n';
	}
	line[i] = 0;
	return (line);
}

Try to read as little as possible each time get_next_line() is
called. If you encounter a new line, you have to return the current
line.
Don’t read the whole file and then process each line.