/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:54:46 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/15 02:00:24 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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
