/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:16 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/19 12:36:15 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing_stack(t_list *stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->content > compare->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int list_size)
{
	int	i;
	int	chunk;

	i = 0;
	if (list_size > 100)
		chunk = 42;
	else
		chunk = 13;
	while (i < list_size)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= chunk + i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	push_optimal_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	moves;

	while (*stack_b)
	{
		max = find_max(*stack_b);
		moves = calculate_moves(*stack_b, max);
		if (moves > 0)
			while ((*stack_b)->index != max)
				rb(stack_b);
		else if (moves < 0)
		{
			while ((*stack_b)->index != max)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	chunks_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5 || size == 4)
		sort_5(stack_a, stack_b);
	else if (size > 5)
	{
		indexing_stack(*stack_a);
		indexing_stack(*stack_b);
		push_chunks_to_b(stack_a, stack_b, size);
		push_optimal_to_a(stack_a, stack_b);
	}
}
