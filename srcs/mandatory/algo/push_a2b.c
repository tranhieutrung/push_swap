/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:32 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 11:28:29 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inside_chunk(t_pushswap *ps, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (ps->a->head->index == i)
			return (i);
		i++;
	}
	return (-1);
}

static int	push_and_rotate_b(t_pushswap *ps, int size)
{
	pb(ps);
	if (ps->b->head->index < (size / 2))
		rb(ps);
	return (1);
}

void	push_a2b(t_pushswap *ps, int size)
{
	int	start;
	int	end;
	int	ivalue;
	int	*pushed_value;

	pushed_value = ft_calloc(size, sizeof(int));
	set_chunk_range(&start, &end, size);
	while (ps->a->size > 3)
	{
		while (!is_chunk_sent(pushed_value, start, end) && ps->a->size)
		{
			ivalue = inside_chunk(ps, start, end);
			if (ivalue != -1 && !pushed_value[ivalue])
				pushed_value[ivalue] = push_and_rotate_b(ps, size);
			else
				ra(ps);
			update_chunk(pushed_value, &start, &end, size);
		}
	}
	if (!is_sorted(ps->a))
		sort_three(ps);
	free(pushed_value);
}
