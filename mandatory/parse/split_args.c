/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:50:03 by hitran            #+#    #+#             */
/*   Updated: 2024/07/03 18:49:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *s)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (*(s + i))
	{
		if (!is_white_space(*(s + i)))
		{
			words++;
			while (*(s + i) && !is_white_space(*(s + i)))
				i++;
		}
		else
			i++;
	}
	return (words);
}

static size_t	word_len(char const *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) && !is_white_space(*(s + i)))
		i++;
	return (i);
}

static char	**split_words(char const *s, char **array, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (*(s + j) && is_white_space(*(s + j)))
			j++;
		*(array + i) = ft_substr(s, j, word_len(s + j));
		if (!*(array + i))
		{
			ft_free_array(i, array);
			return (NULL);
		}
		while (*(s + j) && !is_white_space(*(s + j)))
			j++;
		i++;
	}
	*(array + i) = NULL;
	return (array);
}

char	**split_args(char const *s)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_word(s);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	array = split_words(s, array, words);
	return (array);
}
