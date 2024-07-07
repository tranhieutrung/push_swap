/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:31:13 by hitran            #+#    #+#             */
/*   Updated: 2024/07/05 16:19:53 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	set_number_of_chunks(int size)
{
	if (size < 201)
		return (5);
	else
		return (13);
}

void	set_chunk_range(int *start, int *end, int size)
{
	int	chunk;

	chunk = size / set_number_of_chunks(size);
	*start = (size / 2) - chunk;
	*end = (size / 2) + chunk;
	if (*end >= (size - 3))
		*end = size - 4;
}

int	is_chunk_sent(int *pushed_value, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (pushed_value[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_chunk(int *pushed_value, int *start, int *end, int size)
{
	int	i;

	i = *start;
	while (i < (size / 2))
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == (size / 2))
		*start = *start - (size / set_number_of_chunks(size));
	i = size / 2;
	while (i < *end)
	{
		if (!pushed_value[i])
			break ;
		i++;
	}
	if (i == *end && pushed_value[i])
		*end = *end + (size / set_number_of_chunks(size));
	if (*start < 0)
		*start = 0;
	if (*end >= (size - 3))
		*end = size - 4;
}

/*These number of chunks are chosen based on results of push_swap tester:

No			Moves (100 num)		Moves (500 num)
1			616					10030
2			617					10020
3			541					6847
4			525					6221
5		//	520	///				5282
6			530					5017
7			538					4635
8			554					4503
9			561					4346
10			575					4315
11			594				//	4247	//
12			615					4282
13			638					4271
14			640					4324
15			674					4349
16			673					4405
17			718					4457
18			717					4541
19			713					4590
20			718					4648
25			785					5058
30			879					5640
50			1055				7465
*/