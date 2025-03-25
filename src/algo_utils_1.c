/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:08:55 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/25 11:37:00 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_pos(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

void	sort_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > third && third > second)
		ra(stack);
	else if (second > first && first > third)
		rra(stack);
	else if (second > third && third > first)
	{
		sa(stack);
		ra(stack);
	}
	else if (third > first && first > second)
		sa(stack);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		min_pos = find_smallest_pos(*stack_a);
		if (min_pos <= size / 2)
		{
			while (min_pos > 0)
				(ra(stack_a), min_pos--);
		}
		else
		{
			while (min_pos < size)
				(rra(stack_a), min_pos++);
		}
		pb(stack_a, stack_b);
		size--;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (*stack_b)
		pa(stack_a, stack_b);
}

int	find_max(t_list *stack)
{
	int		max_value;
	int		max_index;
	t_list	*current;

	max_value = INT_MIN;
	max_index = -1;
	current = stack;
	while (current)
	{
		if (current->content > max_value)
		{
			max_value = current->content;
			max_index = current->index;
		}
		current = current->next;
	}
	return (max_index);
}

int	calculate_moves(t_list *stack, int max)
{
	int		moves;
	t_list	*tmp;

	moves = 0;
	tmp = stack;
	while (tmp && tmp->index != max)
	{
		moves++;
		tmp = tmp->next;
	}
	if (moves <= ft_lstsize(stack) / 2)
		return (moves);
	else
		return (-moves);
}
