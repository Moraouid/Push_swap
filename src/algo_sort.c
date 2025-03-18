/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:00:16 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/18 07:31:40 by sel-abbo         ###   ########.fr       */
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

// void	push_chunk(t_list **stack_a, t_list **stack_b, int chunk_min,
// 		int chunk_max)
// {
// 	int	j;
// 	int	pushed;
// 	int	remainder;
// 	int	chunk_size;

// 	j = 0;
// 	pushed = 0;
// 	remainder = ft_lstsize(*stack_a);
// 	chunk_size = chunk_max - chunk_min + 1;
// 	while (j < remainder && *stack_a)
// 	{
// 		if ((*stack_a)->index >= chunk_min && (*stack_a)->index <= chunk_max)
// 		{
// 			pb(stack_a, stack_b);
// 			pushed++;
// 		}
// 		else
// 			ra(stack_a);
// 		if (pushed == chunk_size)
// 			break ;
// 		j++;
// 	}
// }

 void    stack_b_fill(t_list **stack_a, t_list **stack_b, int list_size)
{
    int    i;
    int    range;

    i = 0;
    if (list_size > 100)
        range = 42;
    else
        range = 15;
    while (i < list_size)
    {
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            i++;
        }
        else if ((*stack_a)->index <= range + i)
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
} 

// void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_count)
// {
// 	int	total_size;
// 	int	chunk_size;
// 	int	chunk_max;
// 	int	remainder;
// 	int	i;

// 	total_size = ft_lstsize(*stack_a);
// 	chunk_size = total_size / chunk_count;
// 	remainder = total_size % chunk_count;
// 	indexing_stack(*stack_a);
// 	i = 0;
// 	while (i < chunk_count)
// 	{
// 		chunk_max = (i + 1) * chunk_size - 1;
// 		if (i == chunk_count - 1)
// 			chunk_max += remainder;
// 		push_chunk(stack_a, stack_b, i * chunk_size, chunk_max);
// 		i++;
// 	}
// }

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
			while ((*stack_b)->index != max)
				rrb(stack_b);
		pa(stack_a, stack_b);
		if ((*stack_a) && (*stack_a)->index == max - 1)
			ra(stack_a);
	}
}

void	chunks_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	// int	chunk_count;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5 || size == 4)
		sort_5(stack_a, stack_b);
	else if (size > 5)
	{
		// chunk_count = get_optimal_chunk_count(size);
		stack_b_fill(stack_a, stack_b, size);
		// push_chunks_to_b(stack_a, stack_b, chunk_count);
		push_optimal_to_a(stack_a, stack_b);
	}
}
