/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:55:05 by hitran            #+#    #+#             */
/*   Updated: 2024/07/05 16:06:29 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	is_all_white_space(char *s)
{
	while (*s)
	{
		if (!is_white_space(*s))
			return (0);
		s++;
	}
	return (1);
}

int	argvs_size(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	free_arrays(char **array1, char **array2, char **array3)
{
	free_array(array1);
	free_array(array2);
	free_array(array3);
}

/*
static void	print_index(t_stack *stack, t_node **current, int i)
{
	int len;

	if (stack->size == 0 || !(*current))
	{
		ft_putstr("             ");
		return ;
	}
	len = ft_strlen(ft_itoa((*current)->index));
	if (i < stack->size)
	{
		write(1, "              ", 13 - len - (13 - len) / 2);
		ft_putnbr((*current)->index);
		write(1, "              ", (13 - len) / 2);
		(*current) = (*current)->previous;
	}
	else
		ft_putstr("             ");
}

void	print_stacks(t_pushswap *ps)
{
	int		i;
	t_node	*a_current;
	t_node	*b_current;

	i = 0;
	a_current = ps->a->head;
	b_current = ps->b->head;
	ft_putendl_fd("+------A------+------B------+", 1);
	while (i < ps->a->size || i < ps->b->size)
	{
		ft_putchar('|');
		print_index(ps->a, &a_current, i);
		ft_putchar('|');
		print_index(ps->b, &b_current, i);
		ft_putchar('|');
		ft_putstr("\n");
		i++;
	}
	ft_putendl_fd("+-------------+-------------+", 1);
}
*/