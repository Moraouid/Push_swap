/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:13:36 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/21 01:36:44 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_valid(int argc, char **argv, char ***args)
{
	if (!check_args(argv))
		exit(write(2, "Error\n", 6));
	*args = read_input(argc, argv);
	if (!args)
		exit(write(2, "Error\n", 6));
}

int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*add_to_stack(char **args, int size)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = ft_lstnew(ft_atoi(args[0]));
	a->index = -1;
	i = 1;
	while (i < size)
	{
		b = ft_lstnew(ft_atoi(args[i]));
		b->index = -1;
		ft_lstadd_back(&a, b);
		i++;
	}
	return (a);
}

void	ft_free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
