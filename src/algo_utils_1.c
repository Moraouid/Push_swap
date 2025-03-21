/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:08:55 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/20 22:17:15 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest_index(t_list *stack)
{
	int	min;
	int	index;
	int	i;

	min = INT_MAX;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
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
	int	min_index;
	int	i;

	i = ft_lstsize(*stack_a);
	while (i > 3)
	{
		min_index = find_smallest_index(*stack_a);
		if (min_index <= i / 2)
		{
			while (min_index > 0)
				(ra(stack_a), min_index--);
		}
		else
		{
			while (min_index < i)
				(rra(stack_a), min_index++);
		}
		pb(stack_a, stack_b);
		i--;
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
