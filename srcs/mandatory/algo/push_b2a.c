/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:44 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 11:11:59 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *stack, int highest, int size)
{
	int		position;
	t_node	*node;

	node = stack->head;
	position = 0;
	while (position < size && node)
	{
		if (node->index == highest)
			return (position);
		position++;
		node = node->previous;
	}
	return (-1);
}

static int	sort_a(t_pushswap *ps, int *ra_steps, int *rra_steps, int *highest)
{
	if (ps->a->size == 0)
		return (0);
	if (ps->a->tail->index == *highest)
	{
		rra(ps);
		(*rra_steps)--;
		(*highest)--;
		return (1);
	}
	else if (get_position(ps->a, *highest, *ra_steps) != -1)
	{
		(*ra_steps)--;
		(*highest)--;
		return (1);
	}
	return (0);
}

static int	push_highest(t_pushswap *ps, int *ra_steps,
				int *rra_steps, int *highest)
{
	if (!ps->b->size || *highest != ps->b->head->index)
		return (0);
	while (*ra_steps > 1)
	{
		ra(ps);
		(*ra_steps)--;
		(*rra_steps)++;
	}
	pa(ps);
	if (*ra_steps == 1)
		sa(ps);
	(*highest)--;
	return (1);
}

static int	can_push_to_a(t_pushswap *ps, int *ra_steps, int *rra_steps)
{
	if (!ps->b->size)
		return (0);
	if ((*rra_steps == 0 || ps->b->head->index > ps->a->tail->index))
	{
		while (*ra_steps && ps->b->head->index > ps->a->head->index)
		{
			ra(ps);
			(*ra_steps)--;
			(*rra_steps)++;
		}
		pa(ps);
		(*ra_steps)++;
		return (1);
	}
	return (0);
}

void	push_b2a(t_pushswap *ps, int b_size)
{
	int	ra_steps;
	int	rra_steps;
	int	highest;

	ra_steps = 0;
	rra_steps = 0;
	highest = b_size - 1;
	while (ps->b->size || ra_steps > 0 || rra_steps > 0)
	{
		if (sort_a(ps, &ra_steps, &rra_steps, &highest))
			continue ;
		else if (push_highest(ps, &ra_steps, &rra_steps, &highest))
			continue ;
		else if (can_push_to_a(ps, &ra_steps, &rra_steps))
			continue ;
		else if (get_position(ps->b, highest, ps->b->size) > (ps->b->size / 2))
			rrb(ps);
		else if (get_position(ps->b, highest, ps->b->size) > -1)
			rb(ps);
	}
}
