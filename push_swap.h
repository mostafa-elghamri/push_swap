/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:33:19 by moelgham          #+#    #+#             */
/*   Updated: 2025/02/07 14:33:25 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_elem
{
	int		num;
	int		uses;
	int		index;
}	t_elem;

int		ft_handle_errors(int argc, char **argv);
void	ft_push(t_elem *stack_a, t_elem *stack_b, char *operation);
void	shift_up(t_elem *stack, char *str);
void	shift_down(t_elem *stack, char *str);
t_elem	*create_st(int argc, char **argv, int stok);
void	resolve_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
void	show_stack(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		db_stack(t_elem *stack);
int		last_of_stack(t_elem *stack);
t_elem	max_of_stack(t_elem *stack, int treshold);
t_elem	min_of_stack(t_elem *stack);
int		count_op_ft(t_elem *stack_a, int adr, int reel);
int		count_op_ftb(t_elem *stack_a, t_elem *stack_b, int index);
void	sort_three(t_elem *stack);
void	ft_swap(t_elem *stack, char *msg);
t_elem	ft_min_above_tresh(t_elem *stack, int treshold);
void	ft_double_shift(t_elem *stack_a, t_elem *stack_b, int down_up);
int		count_coherences(t_elem *stack_a, t_elem *stack_b, int index);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		best_index(t_elem *stack_a, t_elem *stack_b, int stack_size);
int		is_sorted(t_elem *stack);
int		is_median(t_elem *stack, int num);
int		args_len(char **split_list);
void	choose_resolve(t_elem *stack_a, t_elem *stack_b, int argc);
void	ft_free_split(char **split_list);
char	**ft_append_str(char **split_list, char *str);
void	ft_free(t_elem *s_a, t_elem *s_b, char **split_list, int tofree);
char	**process_argument(char **split_list, char *arg);
char	**ft_split_mult(const char *str, const char *delimiters);
int		count_words(const char *str, const char *delimiters);
int		is_delimiter(char c, const char *delimiters);

#endif