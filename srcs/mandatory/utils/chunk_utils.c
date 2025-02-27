/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:31:13 by hitran            #+#    #+#             */
/*   Updated: 2024/07/14 13:01:51 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	set_number_of_chunks(int size)
{
	if (size < 201)
		return (5);
	else
		return (13);
}

void	set_chunk_range(int *start, int *end, int size)
{
	int	chunk;

	chunk = size / set_number_of_chunks(size);
	*start = (size / 2) - chunk;
	*end = (size / 2) + chunk;
	if (*end >= (size - 3))
		*end = size - 4;
}

int	is_chunk_sent(int *pushed_value, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (pushed_value[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_chunk(int *pushed_value, int *start, int *end, int size)
{
	int	i;

	i = *start;
	while (i < (size / 2))
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == (size / 2))
		*start = *start - (size / set_number_of_chunks(size));
	i = size / 2;
	while (i < *end)
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == *end && pushed_value[i])
		*end = *end + (size / set_number_of_chunks(size));
	if (*start < 0)
		*start = 0;
	if (*end >= (size - 3))
		*end = size - 4;
}
