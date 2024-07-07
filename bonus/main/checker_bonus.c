/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:26:05 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 19:26:16 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	print_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	execute_operations(t_pushswap *ps, char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		sx(ps->a);
	else if (!ft_strcmp(operation, "sb\n"))
		sx(ps->b);
	else if (!ft_strcmp(operation, "ss\n"))
		ss(ps);
	else if (!ft_strcmp(operation, "pa\n"))
		px(ps->b, ps->a);
	else if (!ft_strcmp(operation, "pb\n"))
		px(ps->a, ps->b);
	else if (!ft_strcmp(operation, "ra\n"))
		rx(ps->a);
	else if (!ft_strcmp(operation, "rb\n"))
		rx(ps->b);
	else if (!ft_strcmp(operation, "rr\n"))
		rr(ps);
	else if (!ft_strcmp(operation, "rra\n"))
		rrx(ps->a);
	else if (!ft_strcmp(operation, "rrb\n"))
		rrx(ps->b);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(ps);
	else
		return (print_error());
	return (0);
}

static int	checker(t_pushswap *ps)
{
	char	buffer[BUFFER_SIZE];
	int		buffer_index;
	int		buffer_size;
	char	*operation;

	buffer_index = 0;
	buffer_size = 0;
	operation = read_line(buffer, &buffer_index, &buffer_size);
	while (operation)
	{
		if (execute_operations(ps, operation))
		{
			free_stacks(ps);
			free(operation);
			return (1);
		}
		free(operation);
		operation = read_line(buffer, &buffer_index, &buffer_size);
	}
	free(operation);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pushswap	ps;

	if (argc < 2)
		return (1);
	ps = (t_pushswap){0};
	if (parse_input(&ps, ++argv))
		return (1);
	if (checker(&ps))
		return (1);
	if (is_sorted(ps.a) && !ps.b->size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(&ps);
	return (0);
}
