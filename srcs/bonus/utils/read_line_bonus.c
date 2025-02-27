/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:35:58 by hitran            #+#    #+#             */
/*   Updated: 2024/07/12 13:25:48 by hitran           ###   ########.fr       */
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

char	*read_line(char *buffer, int *buffer_index, int *buffer_size)
{
	char	*line;
	int		line_length;

	line = malloc(5);
	if (!line)
		return (NULL);
	line_length = 0;
	if (!read_buffer(buffer, buffer_index, buffer_size))
	{
		free(line);
		return (NULL);
	}
	while (buffer[*buffer_index] != '\n')
	{
		if (line_length > 2)
		{
			free(line);
			return (ft_strdup("err"));
		}
		line[line_length++] = buffer[(*buffer_index)++];
	}
	line[line_length] = '\n';
	line[line_length + 1] = '\0';
	(*buffer_index)++;
	return (line);
}
