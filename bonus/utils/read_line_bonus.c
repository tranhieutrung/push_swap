/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:35:58 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 19:23:15 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	read_buffer(char *buffer, int *buffer_index, int *buffer_size)
{
	if (*buffer_index >= *buffer_size)
	{
		*buffer_size = read(0, buffer, BUFFER_SIZE);
		*buffer_index = 0;
		if (*buffer_size <= 0)
			return (0);
	}
	return (1);
}

static char	*expand_line(char *line, int line_length)
{
	char	*new_line;

	new_line = malloc(line_length + BUFFER_SIZE + 1);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line)
	{
		ft_memcpy(new_line, line, line_length);
		free(line);
	}
	return (new_line);
}

char	*read_line(char *buffer, int *buffer_index, int *buffer_size)
{
	char	*line;
	int		line_length;

	line = NULL;
	line_length = 0;
	while (1)
	{
		if (!read_buffer(buffer, buffer_index, buffer_size))
			return (line);
		if (buffer[*buffer_index] == '\n')
		{
			line = expand_line(line, line_length);
			line[line_length] = '\n';
			line[line_length + 1] = '\0';
			(*buffer_index)++;
			return (line);
		}
		line = expand_line(line, line_length);
		line[line_length] = buffer[*buffer_index];
		line_length++;
		(*buffer_index)++;
	}
}
