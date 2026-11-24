/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:00:21 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:34 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	*extract_word(const char *str, const char *delimiters)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !is_delimiter(str[len], delimiters))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = str[len];
	return (word);
}

static void	free_result(char **result, int i)
{
	while (i--)
		free(result[i]);
	free(result);
}

static int	fill_result(char **result, const char *str, const char *delimiters)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && is_delimiter(*str, delimiters))
			str++;
		if (*str && !is_delimiter(*str, delimiters))
		{
			result[i] = extract_word(str, delimiters);
			if (!result[i])
			{
				free_result(result, i);
				return (0);
			}
			i++;
			while (*str && !is_delimiter(*str, delimiters))
				str++;
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split_mult(const char *str, const char *delimiters)
{
	char	**result;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str, delimiters);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, str, delimiters))
		return (NULL);
	return (result);
}
