/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:08:55 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/18 21:21:45 by sel-abbo         ###   ########.fr       */
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
		if (stack->content < min && stack->index == -1)
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

	min_index = find_smallest_index(*stack_a);
	while (min_index--)
		ra(stack_a);
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 4)
	{
		min_index = find_smallest_index(*stack_a);
		while (min_index--)
			ra(stack_a);
		pb(stack_a, stack_b);
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
