/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:29 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 16:39:42 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	args_len(char **split_list)
{
	int	i;

	i = 0;
	while (split_list[i])
		i++;
	return (i);
}

void	choose_resolve(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (argc == 3)
	{
		if (is_sorted(stack_a) == -1)
			ft_swap(stack_a, "sa\n");
	}
	else if (argc == 4)
		sort_three(stack_a);
	else
		resolve_stack(stack_a, stack_b, argc);
}

void	ft_free_split(char **split_list)
{
	int	i;

	if (!split_list)
		return ;
	i = 0;
	while (split_list[i])
	{
		free(split_list[i]);
		i++;
	}
	free(split_list);
}

char	**ft_append_str(char **split_list, char *str)
{
	int		len;
	char	**new_list;
	int		i;

	len = args_len(split_list);
	new_list = malloc((len + 2) * sizeof(char *));
	if (!new_list)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_list[i] = split_list[i];
		i++;
	}
	new_list[len] = ft_strdup(str);
	if (!new_list[len])
	{
		free(new_list);
		return (NULL);
	}
	new_list[len + 1] = NULL;
	free(split_list);
	return (new_list);
}

void	ft_free(t_elem *stack_a, t_elem *stack_b, char **split_lis, int tofree)
{
	int	i;

	if (tofree)
	{
		i = 0;
		while (split_lis[i] != 0)
		{
			free(split_lis[i]);
			i++;
		}
		free(split_lis);
	}
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
}
