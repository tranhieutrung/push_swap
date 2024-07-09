/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:07 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 11:34:04 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
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

void	sa(t_pushswap *ps)
{
	if (!ps->a || ps->a->size < 2)
		return ;
	swap(ps->a);
	ft_putendl_fd("sa", 1);
}
