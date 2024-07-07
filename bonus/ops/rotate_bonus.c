/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:31 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rx(t_stack *stack)
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

void	rr(t_pushswap *ps)
{
	if (!ps)
		return ;
	rx(ps->a);
	rx(ps->b);
}

void	rrx(t_stack *stack)
{
	t_node	*tail_node;

	if (!stack || stack->size < 2)
		return ;
	tail_node = stack->tail;
	stack->tail = stack->tail->next;
	stack->tail->previous = NULL;
	tail_node->next = NULL;
	tail_node->previous = NULL;
	stack->size = stack->size - 1;
	insert_node(tail_node, stack);
}

void	rrr(t_pushswap *ps)
{
	if (!ps)
		return ;
	rrx(ps->a);
	rrx(ps->b);
}
