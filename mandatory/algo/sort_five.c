/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:57:07 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lowest(t_pushswap *ps, int *lowest_index)
{
	int		i;
	int		lowest_position;
	t_node	*current;

	current = ps->a->head;
	*lowest_index = current->index;
	lowest_position = 1;
	i = 1;
	while (current)
	{
		if (current->index < *lowest_index)
		{
			*lowest_index = current->index;
			lowest_position = i;
		}
		current = current->previous;
		i++;
	}
	return (lowest_position);
}

void	sort_five(t_pushswap *ps)
{
	int	lowest_position;
	int	lowest_index;

	if (ps->a->size == 3)
	{
		sort_three(ps);
		return ;
	}
	lowest_index = 0;
	lowest_position = find_lowest(ps, &lowest_index);
	if (ps->a->head->index != lowest_index)
	{
		if (lowest_position <= ps->a->size / 2)
			while (ps->a->head->index != lowest_index)
				ra(ps);
		else
			while (ps->a->head->index != lowest_index)
				rra(ps);
	}
	pb(ps);
	sort_five(ps);
	pa(ps);
}
