/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:36:41 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/17 21:52:46 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sn_output(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	rn_output(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	*stack = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rrn_output(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sn_output(stack_a);
	sn_output(stack_b);
	write(1, "ss\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rn_output(stack_a);
	rn_output(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrn_output(stack_a);
	rrn_output(stack_b);
	write(1, "rrr\n", 4);
}
