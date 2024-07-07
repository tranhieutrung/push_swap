/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:29:51 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 11:39:26 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mylib.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*previous;
	int				index;
	int				value;
}			t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}			t_stack;

typedef struct s_pushswap
{
	t_stack			*a;
	t_stack			*b;
}			t_pushswap;

// PARSE ARGUMENTS
int		parse_input(t_pushswap *ps, char **array);
char	**split_args(char const *s);
void	put_in_stack(t_pushswap *ps, int size, char **array);

// ALGORITHMS
void	sort_three(t_pushswap *ps);
void	sort_five(t_pushswap *ps);
void	push_a2b(t_pushswap *ps, int size);
void	push_b2a(t_pushswap *ps, int size);

// CHUNK UTILS
int		set_number_of_chunks(int size);
void	set_chunk_range(int *start, int *end, int size);
int		is_chunk_sent(int *pushed_value, int start, int end);
void	update_chunk(int *pushed_value, int *start, int *end, int size);

// OPERATIONS
void	sa(t_pushswap *ps);

void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);

void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);

void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);

// UTILS
int		is_white_space(char c);
int		is_all_white_space(char *s);
void	free_array(char **array);
void	free_arrays(char **array1, char **array2, char **array3);
int		argvs_size(char **av);

// STACK UTILS
void	free_stacks(t_pushswap *ps);
int		is_sorted(t_stack *stack);
t_node	*pop(t_stack *stack);
void	insert_node(t_node *node, t_stack *stack);

#endif
