/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:14:16 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:14:39 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_elem *stack)
{
	int	db;
	int	fn;

	db = db_stack(stack);
	fn = last_of_stack(stack);
	if (min_of_stack(stack).index == db && \
	max_of_stack(stack, -1).index == fn)
		return ;
	if (min_of_stack(stack).index == db && \
	max_of_stack(stack, -1).index == fn - 1)
	{
		ft_swap(stack, "sa\n");
		shift_up(stack, "ra\n");
	}
	if (max_of_stack(stack, -1).index == db)
		shift_up(stack, "ra\n");
	if (stack[db].num > stack[db + 1].num)
		ft_swap(stack, "sa\n");
	if (min_of_stack(stack).index == fn)
		shift_down(stack, "rra\n");
}

int	count_op_ft(t_elem *stack_a, int adr, int reel)
{
	int	count_op;
	int	db;
	int	fn;
	int	median;

	count_op = 0;
	db = db_stack(stack_a);
	fn = last_of_stack(stack_a);
	median = db + ((fn - db) / 2);
	if (adr > median)
	{
		count_op = fn - adr + 1;
		if (reel == 1)
			count_op = -count_op;
	}
	else if (adr <= median)
		count_op = adr - db;
	return (count_op);
}

int	count_op_ftb(t_elem *a, t_elem *b, int index)
{
	int		c_op;
	int		dest;
	t_elem	min_dest;

	c_op = 0;
	c_op += count_op_ft(a, index, 0);
	if (min_of_stack(b).num > a[index].num \
	|| max_of_stack(b, -1).num < a[index].num)
		c_op += count_op_ft(b, min_of_stack(b).index, 0);
	else
	{
		min_dest = ft_min_above_tresh(b, a[index].num);
		c_op += count_op_ft(b, b[min_dest.index].index, 0);
	}
	dest = count_coherences(a, b, index);
	if (dest < 0)
		dest = -dest;
	c_op = c_op - dest;
	return (c_op + 1);
}

int	count_coherences(t_elem *stack_a, t_elem *stack_b, int index)
{
	int	op_a;
	int	op_b;
	int	dist;
	int	min;

	op_a = count_op_ft(stack_a, index, 1);
	if (min_of_stack(stack_b).num > stack_a[index].num || \
	max_of_stack(stack_b, -1).num < stack_a[index].num)
		op_b = count_op_ft(stack_b, min_of_stack(stack_b).index, 1);
	else
	{
		min = ft_min_above_tresh(stack_b, stack_a[index].num).index;
		op_b = count_op_ft(stack_b, min, 1);
	}
	dist = 0;
	if (op_a > 0 && op_b > 0)
		dist = ft_min(op_a, op_b);
	if (op_a < 0 && op_b < 0)
		dist = ft_max(op_a, op_b);
	return (dist);
}

int	best_index(t_elem *stack_a, t_elem *stack_b, int stack_size)
{
	int		cost;
	int		db;
	t_elem	conti;

	db = db_stack(stack_a);
	conti.num = -1;
	while (db < stack_size - 1)
	{
		cost = count_op_ftb(stack_a, stack_b, db);
		if (cost < conti.num || conti.num == -1)
		{
			conti.num = cost;
			conti.index = db;
		}
		db++;
	}
	return (conti.index);
}
