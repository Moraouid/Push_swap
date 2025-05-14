/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:00:35 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/22 09:46:55 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (len == 1)
		return (ft_free(args), 0);
	len = ft_len(args);
	if (len == 1)
		return (ft_free(args), 0);
	stack_a = add_to_stack(args, len);
	if (!stack_a)
		return (ft_free(args), 0);
	ft_free(args);
	if (is_sorted(stack_a))
		return (ft_free_lst(stack_a), 0);
	chunks_sort(&stack_a, &stack_b);
	ft_free_lst(stack_a);
	return (0);
}
