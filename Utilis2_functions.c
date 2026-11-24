/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilis2_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:20:41 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:20:44 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_elem	*create_st(int argc, char **argv, int stok)
{
	t_elem	*tab;
	int		i;

	tab = malloc(sizeof(t_elem) * (argc + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (stok == 1)
		{
			tab[i].num = ft_atoi(argv[i]);
			tab[i].uses = 1;
		}
		else
		{
			tab[i].num = 0;
			tab[i].uses = 0;
		}
		tab[i].index = i;
		i++;
	}
	tab[i].index = -1;
	return (tab);
}

t_elem	min_of_stack(t_elem *stack)
{
	int	start;
	int	end;
	int	min;

	start = db_stack(stack);
	end = last_of_stack(stack);
	min = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min].num)
			min = stack[start].index;
		start++;
	}
	return (stack[min]);
}

t_elem	max_of_stack(t_elem *stack, int treshold)
{
	int	start;
	int	end;
	int	max;

	start = db_stack(stack);
	end = last_of_stack(stack);
	max = -1;
	while (start <= end)
	{
		if (max == -1 || ((stack[start].num > stack[max].num || \
		stack[max].uses == -1) && (treshold == -1 || \
		stack[start].num < treshold)))
			max = stack[start].index;
		start++;
	}
	return (stack[max]);
}

t_elem	ft_min_above_tresh(t_elem *stack, int treshold)
{
	int	start;
	int	end;
	int	min;

	start = db_stack(stack);
	end = last_of_stack(stack);
	min = -1;
	while (start <= end)
	{
		if (stack[start].num > treshold && \
		(min == -1 || stack[start].num < stack[min].num))
			min = stack[start].index;
		start++;
	}
	if (min == -1)
		return (min_of_stack(stack));
	return (stack[min]);
}

int	is_sorted(t_elem *stack)
{
	int	i;

	i = 0;
	while (stack[i + 1].index != -1)
	{
		if (stack[i].num > stack[i + 1].num)
			return (-1);
		i++;
	}
	return (1);
}
