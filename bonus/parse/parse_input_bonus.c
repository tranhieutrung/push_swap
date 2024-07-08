/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:57:26 by hitran            #+#    #+#             */
/*   Updated: 2024/07/08 14:26:49 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	handle_error(char **s1, char **s2)
{
	free_array(s1);
	free_array(s2);
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	is_int(char *s)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (is_white_space(*s))
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -1;
	if (*s < '0' || *s > '9')
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		number = number * 10 + *s++ - '0';
		if ((number * sign < MIN_INT) || (number * sign > MAX_INT))
			return (0);
	}
	while (is_white_space(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}

static int	is_invalid(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		if (*array[i] == '\0' || is_all_white_space(array[i]))
			return (1);
		if (!is_int(array[i]))
			return (1);
		j = -1;
		while (++j < i)
			if (ft_atoi(array[j]) == ft_atoi(array[i]))
				return (1);
	}
	return (0);
}

char	**join_array(char **array1, char **array2)
{
	char	**array;
	int		i;
	int		j;

	array = (char **)ft_calloc(argvs_size(array1) + argvs_size(array2) + 1,
			sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (array1 && array1[i])
	{
		array[i] = ft_strdup(array1[i]);
		if (!array[i++])
			return (free_arrays(array1, array2, array));
	}
	j = 0;
	while (array2 && array2[j])
	{
		array[i + j] = ft_strdup(array2[j]);
		if (!array[i + j++])
			return (free_arrays(array1, array2, array));
	}
	free_arrays(array1, array2, NULL);
	return (array);
}

int	parse_input(t_pushswap *ps, char **av)
{
	char	**temp;
	char	**array;
	int		size;

	array = NULL;
	while (*av)
	{
		temp = split_args(*av);
		if (!temp || !argvs_size(temp) || is_invalid(temp))
			return (handle_error(temp, array));
		array = join_array(array, temp);
		size = argvs_size(array);
		if (!array || !size || is_invalid(array))
			return (handle_error(NULL, array));
		av++;
	}
	put_in_stack(ps, size, array);
	free_array(array);
	return (0);
}
