/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:07 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 18:34:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	px(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2 || !stack1->size)
		return ;
	insert_node(pop(stack1), stack2);
}

void	sx(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = pop(stack);
	second = pop(stack);
	insert_node(first, stack);
	insert_node(second, stack);
}

void	ss(t_pushswap *ps)
{
	if (!ps)
		return ;
	sx(ps->a);
	sx(ps->b);
}
