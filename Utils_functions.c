/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:22:04 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:22:07 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	db_stack(t_elem *stack)
{
	int	first;

	first = 0;
	while (stack[first].uses != 1)
		first++;
	if (stack[first].index == -1)
		first--;
	return (first);
}

int	last_of_stack(t_elem *stack)
{
	int	end;

	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}

int	is_median(t_elem *stack, int num)
{
	int	start;
	int	end;
	int	max;
	int	min;

	start = db_stack(stack);
	end = last_of_stack(stack);
	max = 0;
	min = 0;
	while (start <= end)
	{
		if (stack[start].num > num)
			max++;
		else if (stack[start].num < num)
			min++;
		start++;
	}
	if ((max - min) >= -1 && (max - min) <= 1)
		return (1);
	return (0);
}
