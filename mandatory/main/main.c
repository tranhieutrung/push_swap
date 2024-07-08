/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:26:05 by hitran            #+#    #+#             */
/*   Updated: 2024/07/05 11:41:40 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_pushswap *ps)
{
	if (ps->a->size == 2 && ps->a->head->value > ps->a->head->previous->value)
		sa(ps);
	else if (ps->a->size == 3)
		sort_three(ps);
	else if (ps->a->size <= 5)
		sort_five(ps);
	else
	{
		push_a2b(ps, ps->a->size);
		push_b2a(ps, ps->b->size);
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (argc < 2)
		return (1);
	ps = (t_pushswap){0};
	if (parse_input(&ps, ++argv))
		return (1);
	if (!is_sorted(ps.a) || ps.b->size)
		sort_stack(&ps);
	free_stacks(&ps);
	return (0);
}
