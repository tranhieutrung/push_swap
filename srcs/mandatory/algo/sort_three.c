/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:59 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pushswap *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->a->head->index;
	second = ps->a->head->previous->index;
	third = ps->a->head->previous->previous->index;
	if (first > second && second > third)
	{
		sa(ps);
		rra(ps);
	}
	else if (first > third && third > second)
		ra(ps);
	else if (second > first && first > third)
		rra(ps);
	else if (third > first && first > second)
		sa(ps);
	else if (second > third && third > first)
	{
		sa(ps);
		ra(ps);
	}
}
