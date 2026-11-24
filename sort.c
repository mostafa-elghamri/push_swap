/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:28:03 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:28:12 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	duble_number(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		if (ft_atoi(argv[0]) == 2147483650)
			return (-1);
	}
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_atoi(argv[i]) == 2147483650 \
				|| ft_atoi(argv[j]) == 2147483650)
				return (-1);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				if (!(j == 0 && argv[i][j] == '-'))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_handle_errors(int argc, char **argv)
{
	if (is_number(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (duble_number(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	return (1);
}

char	**process_argument(char **split_list, char *arg)
{
	char	**temp;
	int		j;

	temp = ft_split_mult(arg, " ");
	if (!temp || !temp[0])
	{
		ft_free_split(temp);
		ft_free_split(split_list);
		return (NULL);
	}
	if (!split_list)
		return (temp);
	j = 0;
	while (temp[j])
	{
		split_list = ft_append_str(split_list, temp[j]);
		if (!split_list)
		{
			ft_free_split(temp);
			return (NULL);
		}
		j++;
	}
	ft_free_split(temp);
	return (split_list);
}
