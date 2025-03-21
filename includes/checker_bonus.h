/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:41 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/21 01:45:18 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line/get_next_line.h"
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
void	is_valid(int argc, char **argv, char ***args);
int		ft_len(char **str);
int		check_duplicates(char **args);
int		is_sorted(t_list *stack);
void	ft_free_lst(t_list *lst);
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