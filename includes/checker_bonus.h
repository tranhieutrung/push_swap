/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:29:51 by hitran            #+#    #+#             */
/*   Updated: 2024/07/07 19:13:52 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// OPERATIONS
void	sx(t_stack *stack);
void	ss(t_pushswap *ps);

void	px(t_stack *stack1, t_stack *stack2);

void	rx(t_stack *stack);
void	rr(t_pushswap *ps);

void	rrx(t_stack *stack);
void	rrr(t_pushswap *ps);

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
char	*read_line(char *buffer, int *buffer_index, int *buffer_size);

#endif
