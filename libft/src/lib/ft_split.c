/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:31:36 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:16:33 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	*free_all(char **matrix, int j)
{
	if (!matrix)
		return (NULL);
	while (j > 0)
	{
		free(matrix[--j]);
	}
	free(matrix);
	return (NULL);
}

static char	**allocate_words(char const *s, char c, char **matrix)
{
	int	i;
	int	j;
	int	start;

	if (!s || !matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			matrix[j] = ft_substr(s, start, i - start);
			if (!matrix[j])
				return (free_all(matrix, j));
			j++;
		}
	}
	matrix[j] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	matrix = malloc(sizeof(char *) * (words + 1));
	if (!matrix)
		return (NULL);
	return (allocate_words(s, c, matrix));
}
