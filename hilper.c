/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:08:12 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/08 22:08:16 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_delimiter(char c, const char *delimiters)
{
	while (*delimiters)
	{
		if (c == *delimiters)
			return (1);
		delimiters++;
	}
	return (0);
}

int	count_words(const char *str, const char *delimiters)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_delimiter(*str, delimiters) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_delimiter(*str, delimiters))
			in_word = 0;
		str++;
	}
	return (count);
}
