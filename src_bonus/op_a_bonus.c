/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:29:34 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/21 00:45:25 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ra(t_list **stack)
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

void	rra(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stack;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}
