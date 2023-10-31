/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellier <apellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:58:22 by apellier          #+#    #+#             */
/*   Updated: 2023/06/12 15:18:06 by apellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	empty_buffer(char (*buffer)[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		(*buffer)[i] = 0;
		i++;
	}
}

void	rm_elem_from_buffer(char (*buffer)[], int nbr)
{
	int	i;

	i = 0;
	while ((*buffer)[nbr] != 0)
	{
		(*buffer)[i] = (*buffer)[nbr];
		i++;
		nbr++;
	}
	(*buffer)[i] = 0;
}

size_t	strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*free_malloc(char *s1)
{
	if (s1[0])
		free (s1);
	return (NULL);
}

char	*join_lines(char *s1, char *s2, int n)
{
	char	*join;
	int		i;
	int		j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = strlen_gnl(s1) + strlen_gnl(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (free_malloc(s1));
	i = 0;
	while (s1[i] != 0)
	{
		join[i] = s1[i];
		i++;
	}
	free_malloc(s1);
	j = 0;
	while (s2[j] != 0 && j <= n)
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}
