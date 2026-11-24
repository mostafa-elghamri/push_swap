/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:12:21 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 16:12:26 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**split_all_args(int *argc, char **argv, int *tofree)
{
	char	**split_list;
	int		i;

	split_list = NULL;
	i = 0;
	while (argv[i])
	{
		split_list = process_argument(split_list, argv[i]);
		if (!split_list)
			return (NULL);
		i++;
	}
	*argc = args_len(split_list) + 1;
	*tofree = 1;
	return (split_list);
}

int	prepare_data(int argc, char **argv, char ***split_list, int *tofree)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	argv++;
	*split_list = split_all_args(&argc, argv, tofree);
	if (!*split_list)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (*split_list == NULL || (argc == 1 && (*split_list)[0][0] == '\0'))
	{
		ft_free(NULL, NULL, *split_list, *tofree);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (argc);
}

int	db_stacks(int argc, char **split_list, t_elem **stack_a, t_elem **stack_b)
{
	*stack_a = create_st(argc, split_list, 1);
	*stack_b = create_st(argc, split_list, 0);
	if (!*stack_a || !*stack_b)
	{
		ft_free(*stack_a, *stack_b, split_list, 1);
		return (-1);
	}
	return (0);
}

void	handle_resolution(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (is_sorted(stack_a) == -1)
		choose_resolve(stack_a, stack_b, argc);
}

int	main(int argc, char **argv)
{
	int		error;
	t_elem	*stack_a;
	t_elem	*stack_b;
	char	**split_list;
	int		tofree;

	argc = prepare_data(argc, argv, &split_list, &tofree);
	if (argc == -1)
		return (0);
	error = ft_handle_errors(argc, split_list);
	if (error == -1 || error == 0)
	{
		ft_free(NULL, NULL, split_list, tofree);
		return (0);
	}
	if (db_stacks(argc, split_list, &stack_a, &stack_b) == -1)
		return (-1);
	handle_resolution(stack_a, stack_b, argc);
	ft_free(stack_a, stack_b, split_list, tofree);
	return (0);
}
