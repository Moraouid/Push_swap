/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:00:35 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/11 02:44:12 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>
#include <stdio.h>

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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

int	check_duplicates(char **args)
{
	int i, j;
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	long	nb;

	int(i), (sign);
	(i = 0), (sign = 1), (nb = 0);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if ((nb * sign) < INT_MIN || (nb * sign) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_args(int size, char **av)
{
	char	**split;

	int(count), (i), (j);
	count = 0;
	i = 0;
	while (i < size)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free(split);
		i++;
	}
	return (count);
}

void	ft_join(char **split, char **args, int *k)
{
	int	j;

	j = 0;
	while (split[j])
	{
		args[*k] = ft_strdup(split[j]);
		if (!is_valid_number(args[*k]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free(args);
			ft_free(split);
			exit(1);
		}
		j++;
		(*k)++;
	}
}
int	ft_strlen_without_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

int	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen_without_spaces(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**read_input(int ac, char **av)
{
	char(**args), (**split);
	int(i), (k), (count);
	(i = 1), (k = 0);
	count = 0;
	if (ac < 2)
		exit(1);
	count = count_args(ac, av);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (0);
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (split == NULL)
		{
			free(split);
			free(args);
			exit(write(2, "Error\n", 6));
		}
		ft_join(split, args, &k);
		ft_free(split);
		i++;
	}
	args[k] = NULL;
	return (args);
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

int	find_smallest_index(t_list *stack, int flag)
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
	if (flag == 1)
		return (min);
	return (index);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = find_smallest_index(*stack_a, 0);
	while (min_index--)
		ra(stack_a);
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 4)
	{
		min_index = find_smallest_index(*stack_a, 0);
		while (min_index--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (*stack_b)
		pa(stack_a, stack_b);
}

void	indexing_stack(t_list *stack)
{
	t_list	*tmp;
	int		min;
	int		size;
	int		i;
	tmp = stack;
	size = ft_lstsize(stack);
	i = 0;
	while (i < size)
	{
		stack = tmp;
		min = find_smallest_index(stack, 1);
		while(stack)
		{
			if(stack->content == min)
				stack->index = i;
			stack = stack->next;
		}
		i++;
	}
}
// void lfassi(t_list *stack_a, t_list *stack_b)
// {
// 	if (x == stack_a)
// 		ra(&stack_a);
// 	if(x == stack_b)
// 		pa(&stack_a, &stack_b);
// 	if (x == stack_a->next->content)
// 		sa(&stack_a);
// 	if (x == stack_b->next->content)
// 		sb(&stack_a, &stack_b);
// 	if(x == stack_a->next->content && x_n == stack_a->next->next->content)
// 		ss(&stack_a, &stack_b);
// 	if(ft_lstlast(stack_b)->content == x)
// 		rrb(&stack_b);
// 	if(ft_lstlast(stack_a)->content == x)
// 		rra(&stack_a);
// 	if(ft_lstlast(stack_b)->content == x && ft_lstlast(stack_b)->prev->content == x_n)
// 		rrr(&stack_a, &stack_b);
// }

void	reindexing_stack(t_list *stack)
{
	t_list	*tmp;
	int		size;
	int		i;
	tmp = stack;
	size = ft_lstsize(stack);
	i = 0;
	while (i < size)
	{
		stack = tmp;
		while(stack)
		{
			stack->index = -1;
			stack = stack->next;
		}
		i++;
	}
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
    int i;
    int size;
    int middle;
    
    indexing_stack(*stack_a);
    size = ft_lstsize(*stack_a);
    middle = size / 2;
    i = 0;
    while (size > i)
    {
		
        if ((*stack_a)->index <= middle)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        i++;
    }
	while(*stack_b)
	{
		i = 0;
		reindexing_stack(*stack_b);
		indexing_stack(*stack_b);
		size = ft_lstsize(*stack_b);
		middle = size / 2;
		while(size > i)
		{
			if(ft_lstsize(*stack_b) == 1)
			{
				pa(stack_a, stack_b);
				break;
			}
			if ((*stack_b)->index >= middle)
				pa(stack_a, stack_b);
			else
				rb(stack_b);
			i++;
		}
	}
		
}



void	final_sort(t_list **stack_a)
{
	int i;
	int size;
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size -1)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
        {
            sa(stack_a);
        }
        ra(stack_a);
        i++;
    }
	ra(stack_a);
}


int	main(int argc, char **argv)
{
	char	**args;
	int		len;
	int		size;
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
	size = ft_lstsize(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size == 5 || size == 4)
		sort_5(&stack_a, &stack_b);
	if(size > 5)
	{
		quick_sort(&stack_a, &stack_b);
		// quick_sort(&stack_a, &stack_b);
		while (1)
		{
			final_sort(&stack_a);
			if (is_sorted(stack_a))
				break;
		}
		
	}
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

