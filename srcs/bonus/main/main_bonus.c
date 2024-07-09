/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:26:05 by hitran            #+#    #+#             */
/*   Updated: 2024/07/08 14:33:35 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
