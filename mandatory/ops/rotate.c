/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:31 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*popped;

	if (!stack || stack->size < 2)
		return ;
	popped = pop(stack);
	stack->tail->previous = popped;
	popped->next = stack->tail;
	popped->previous = NULL;
	stack->tail = popped;
	stack->size = stack->size + 1;
}

void	ra(t_pushswap *ps)
{
	rotate(ps->a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_pushswap *ps)
{
	rotate(ps->b);
	ft_putendl_fd("rb", 1);
}

/*
void	rr(t_pushswap *ps)
{
	ra(ps);
	rb(ps);
	ft_putendl_fd("rr", 1);
}
*/