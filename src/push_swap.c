/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:00:35 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/15 03:54:53 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
void	sa(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write(1, "sa\n", 3);
}
void	sb(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write(1, "sb\n", 3);
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
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
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
	write(1, "rb\n", 3);
}

void	rra(t_list **stack)
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
	write(1, "rra\n", 4);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	rrb(t_list **stack)
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
	write(1, "rrb\n", 4);
}

void sn_output(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void rn_output(t_list **stack)
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

void rrn_output(t_list **stack)
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

void ss(t_list **stack_a, t_list **stack_b)
{
    sn_output(stack_a);
    sn_output(stack_b);
    write(1, "ss\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rn_output(stack_a);
    rn_output(stack_b);
    write(1, "rr\n", 3);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rrn_output(stack_a);
    rrn_output(stack_b);
    write(1, "rrr\n", 4);
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

int get_optimal_chunk_count(int stack_size)
{
    if (stack_size <= 100)
        return 5;
    else
        return 12;
}

int find_max(t_list *stack)
{
	int max_value = INT_MIN;
	int max_index = -1;
	t_list *current = stack;

	while (current)
	{
		if (current->content > max_value)
		{
			max_value = current->content;
			max_index = current->index;
		}
		current = current->next;
	}
	return max_index;
}

void indexing_stack(t_list *stack)
{
    t_list *current = stack;
    t_list *compare;
    int index;
    
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

int calculate_moves(t_list *stack, int max)
{
    int moves = 0;
    t_list *tmp = stack;
    while (tmp && tmp->index != max)
    {
        moves++;
        tmp = tmp->next;
    }
	if(moves <= ft_lstsize(stack) / 2)
		return (moves);
	else
		return (-moves);
}

void push_optimal_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        int max = find_max(*stack_b);
        int moves = calculate_moves(*stack_b, max);
        
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



void push_chunk(t_list **stack_a, t_list **stack_b, int chunk_min, int chunk_max, int chunk_size)
{
	int j;
	int pushed;
	int remaining;
	
	pushed = 0;
	j = 0;
	remaining = ft_lstsize(*stack_a);
	while (j < remaining && *stack_a)
	{
		if ((*stack_a)->index >= chunk_min && (*stack_a)->index <= chunk_max)
			{
				pb(stack_a, stack_b);
				pushed++;
			}
		else
			ra(stack_a);
		if(pushed == chunk_size)
				break;
		j++;
	}
}

void push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_count)
{
    int total_size;
    int chunk_size;
	int chunk_min;
	int chunk_max;
    int i;
    
	total_size = ft_lstsize(*stack_a);
	chunk_size = total_size / chunk_count;
    indexing_stack(*stack_a);
	i = 0;
	while (i < chunk_count)
	{
		chunk_min = i * chunk_size;
		chunk_max = (i + 1) * chunk_size - 1;
		if (i == chunk_count - 1)
			chunk_max = total_size - 1;
		push_chunk(stack_a, stack_b, chunk_min, chunk_max, chunk_size);
		i++;
	}
}

void chunks_sort(t_list **stack_a, t_list **stack_b)
{
    int size;
	int chunk_count;
	
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5 || size == 4)
		sort_5(stack_a, stack_b);
	else if (size > 5)
	{
    	chunk_count = get_optimal_chunk_count(size);
    	push_chunks_to_b(stack_a, stack_b, chunk_count);
    	push_optimal_to_a(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (!check_args(argv))
		exit(write(1, "Error\n", 6));
	args = read_input(argc, argv);
	if (!args)
		exit(write(1, "Error\n", 6));
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
	// printf("stack_a\n");
	// while(stack_a)
	// {
	// 	printf("%d\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// printf("stack_b\n");
	// while(stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	ft_free_lst(stack_a);
	ft_free(args);
	return (0);
}
