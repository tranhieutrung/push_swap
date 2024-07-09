/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:18:12 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
