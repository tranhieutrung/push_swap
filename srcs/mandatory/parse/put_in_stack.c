/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:18:12 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_next_max(t_stack *stack)
{
	t_node	*max;
	t_node	*current;

	max = NULL;
	current = stack->head;
	while (current)
	{
		if ((current->index == 0) && (!max || current->value > max->value))
			max = current;
		current = current->previous;
	}
	return (max);
}

static void	set_index(t_stack *stack, int size)
{
	int		index;
	t_node	*current;

	index = size;
	current = get_next_max(stack);
	while (index-- > 0)
	{
		current->index = index;
		current = get_next_max(stack);
	}
}

static t_stack	*create_stack(char **array, int size)
{
	int		i;
	t_stack	*stack;
	t_node	*node;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = size;
	while (i--)
	{
		node = ft_calloc(1, sizeof(t_node));
		if (!node)
			return (NULL);
		node->value = ft_atoi(array[i]);
		insert_node(node, stack);
	}
	return (stack);
}

void	put_in_stack(t_pushswap *ps, int size, char **array)
{
	ps->a = create_stack(array, size);
	ps->b = ft_calloc(1, sizeof(t_stack));
	if (!ps-> a || !ps->b)
		return ;
	set_index(ps->a, size);
}
