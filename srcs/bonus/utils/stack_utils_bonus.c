/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:52:07 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 16:34:49 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stacks(t_pushswap *ps)
{
	t_node	*tmp;

	if (ps->a)
	{
		while (ps->a->head)
		{
			tmp = ps->a->head;
			ps->a->head = ps->a->head->previous;
			free(tmp);
		}
		free(ps->a);
	}
	if (ps->b)
	{
		while (ps->b->head)
		{
			tmp = ps->b->head;
			ps->b->head = ps->b->head->previous;
			free(tmp);
		}
		free(ps->b);
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	while (temp->previous)
	{
		if (temp->value > temp->previous->value)
			return (0);
		temp = temp->previous;
	}
	return (1);
}

t_node	*pop(t_stack *stack)
{
	t_node	*popnode;

	if (!stack || (!stack->head && !stack->tail))
		return (NULL);
	if (stack->head == stack->tail)
	{
		popnode = stack->head;
		stack->head = NULL;
		stack->tail = NULL;
		stack->size = stack->size - 1;
		return (popnode);
	}
	popnode = stack->head;
	stack->head = stack->head->previous;
	stack->head->next = NULL;
	popnode->previous = NULL;
	stack->size = stack->size - 1;
	return (popnode);
}

void	insert_node(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		stack->size = 1;
		return ;
	}
	stack->head->next = node;
	node->previous = stack->head;
	node->next = NULL;
	stack->head = stack->head->next;
	stack->size = stack->size + 1;
}
