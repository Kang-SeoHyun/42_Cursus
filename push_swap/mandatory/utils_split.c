/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:17:44 by seokang           #+#    #+#             */
/*   Updated: 2022/12/15 23:23:18 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

static char	*str_copy(char **str, char charset)
{
	int		word_len;
	int		count;
	char	*copy;

	word_len = 0;
	while (*(*str) && !is_charset(*(*str), charset))
	{
		word_len++;
		*str++;
	}
	*str -= word_len;
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (0);
	count = 0;
	while (*(*str) && ++count <= word_len)
		*copy++ = *(*str)++;
	*copy = '\0';
	copy -= word_len;
	return (copy);
}

static char	**free_copy(char **str, int size)
{
	int	index;

	index = 0;
	while (++index < size)
	{
		free(str[index]);
		index++;
	}
	free(str);
	return (0);
}

char	**ft_split(char *str, char charset)
{
	char	**copy;
	int		words;
	int		index;

	if (!str)
		return (0);
	words = count_word(str, charset);
	copy = malloc(sizeof(char *) * (words + 1));
	if (!copy)
		return (0);
	index = 0;
	while (index < words)
	{
		while (*str && is_charset(*str, charset))
			++str;
		copy[index] = str_copy(&str, charset);
		if (!copy[index])
			return (free_copy(copy, index));
		index++;
	}
	copy[index] = 0;
	return (copy);
}
