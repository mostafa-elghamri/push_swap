/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:19:31 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:19:34 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_coherences(t_elem *stack_a, t_elem *stack_b, int index)
{
	int	dist;

	dist = count_coherences(stack_a, stack_b, index);
	if (dist > 0)
	{
		while (dist > 0)
		{
			ft_double_shift(stack_a, stack_b, 0);
			dist--;
		}
	}
	else if (dist < 0)
	{
		dist = -dist;
		while (dist > 0)
		{
			ft_double_shift(stack_a, stack_b, 1);
			dist--;
		}
	}
}

int	rotatiom_at_top(t_elem *stack_a, int index, char *r, char *rr)
{
	int	op;
	int	cp;
	int	sin;

	cp = count_op_ft(stack_a, index, 1);
	sin = cp;
	if (cp < 0)
		cp = -cp;
	op = cp;
	if (cp != 0)
	{
		while (cp > 0)
		{
			if (sin > 0)
				shift_up(stack_a, r);
			else
				shift_down(stack_a, rr);
			cp--;
		}
	}
	if (sin > 0)
		sin = 1;
	else
		sin = -1;
	return (sin * op);
}

int	get_median(t_elem *stack)
{
	int	db;
	int	fn;

	db = db_stack(stack);
	fn = last_of_stack(stack);
	while (db <= fn)
	{
		if (is_median(stack, stack[db].num))
			return (stack[db].num);
		db++;
	}
	return (-1);
}

void	resolve_num(t_elem *stack_a, t_elem *stack_b, int index, int stack_size)
{
	int	db;
	int	same;

	db = db_stack(stack_a);
	same = count_coherences(stack_a, stack_b, index);
	resolve_coherences(stack_a, stack_b, index);
	if (same != 0)
		index -= same;
	if (index >= stack_size - 2)
		index = db + (index - (stack_size - 1));
	else if (index < db)
		index = last_of_stack(stack_a) + index;
	index -= rotatiom_at_top(stack_a, index, "rb\n", "rrb\n");
	if (index >= stack_size - 2)
		index = db + (index - (stack_size - 1));
	if (min_of_stack(stack_b).num > stack_a[index].num \
	|| max_of_stack(stack_b, -1).num < stack_a[index].num)
		rotatiom_at_top(stack_b, min_of_stack(stack_b).index, "ra\n", "rra\n");
	else
		rotatiom_at_top(stack_b, \
	ft_min_above_tresh(stack_b, stack_a[index].num).index, "ra\n", "rra\n");
	ft_push(stack_a, stack_b, "pa\n");
}

void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size)
{
	int	index;
	int	median;

	index = db_stack(stack_a);
	median = get_median(stack_a);
	while (index < stack_size - 4)
	{
		ft_push(stack_a, stack_b, "pb\n");
		if (stack_b[db_stack(stack_b)].num > median \
		&& last_of_stack(stack_a) - db_stack(stack_a) + 1 > 3)
			shift_up(stack_b, "rb\n");
		index++;
	}
	sort_three(stack_a);
	index = db_stack(stack_b);
	while (index < last_of_stack(stack_b))
	{
		resolve_num(stack_b, stack_a, \
		best_index(stack_b, stack_a, stack_size), stack_size);
		index++;
	}
	rotatiom_at_top(stack_a, \
	ft_min_above_tresh(stack_a, stack_b[index].num).index, "ra\n", "rra\n");
	ft_push(stack_b, stack_a, "pa\n");
	rotatiom_at_top(stack_a, min_of_stack(stack_a).index, "ra\n", "rra\n");
}
