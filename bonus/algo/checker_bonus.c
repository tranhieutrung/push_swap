/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:32:53 by hitran            #+#    #+#             */
/*   Updated: 2024/07/08 14:54:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	print_error(void)
{
	ft_putendl_fd("Error", 1);
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

int	checker(t_pushswap *ps)
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
