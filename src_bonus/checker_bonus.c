/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:57:00 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/25 12:35:06 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	operation_ss_rr_rrr(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "ss\n", 3))
	{
		sa(stack_a);
		sb(stack_b);
	}
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		rra(stack_a);
		rrb(stack_b);
	}
}

int	execute_operation(char *op, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(op, "rr\n", 3) || !ft_strncmp(op, "rrr\n", 4)
		|| !ft_strncmp(op, "ss\n", 3))
		operation_ss_rr_rrr(op, stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	apply_operations(t_list **stack_a, t_list **stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!execute_operation(operation, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			free(operation);
			ft_free_lst(*stack_b);
			get_next_line(-1);
			return ;
		}
		free(operation);
		operation = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	is_valid(argc, argv, &args);
	len = ft_len(args);
	stack_a = add_to_stack(args, len);
	if (!stack_a)
		return (ft_free(args), 0);
	apply_operations(&stack_a, &stack_b);
	if (stack_b)
		ft_free_lst(stack_b);
	ft_free_lst(stack_a);
	ft_free(args);
	return (0);
}
