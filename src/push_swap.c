/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:00:35 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/19 12:35:14 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_valid(int argc, char **argv, char ***args)
{
	if (!check_args(argv))
		exit(write(1, "Error\n", 6));
	*args = read_input(argc, argv);
	if (!args)
		exit(write(1, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	char	**args;
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	is_valid(argc, argv, &args);
	len = ft_len(args);
	if (len == 1)
		return (ft_free(args), 0);
	if (!check_duplicates(args))
	{
		write(1, "Error\n", 6);
		ft_free(args);
		exit(1);
	}
	stack_a = add_to_stack(args, len);
	if (is_sorted(stack_a))
		return (ft_free_lst(stack_a), 0);
	chunks_sort(&stack_a, &stack_b);
	ft_free_lst(stack_a);
	ft_free(args);
	return (0);
}
