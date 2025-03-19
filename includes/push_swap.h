/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:37:52 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/19 12:37:53 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_join(char **split, char **args, int *k);
char	**read_input(int ac, char **av);
int		count_args(int size, char **av);
void	ft_free(char **str);
int		check_args(char **args);
int		check_duplicates(char **args);
int		is_sorted(t_list *stack);
void	chunks_sort(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		get_optimal_chunk_count(int size);
int		find_max(t_list *stack);
int		calculate_moves(t_list *stack, int max);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
t_list	*add_to_stack(char **args, int size);
void	ft_free_lst(t_list *lst);
int		ft_len(char **str);

#endif