/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-abbo <sel-abbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:02:38 by sel-abbo          #+#    #+#             */
/*   Updated: 2025/03/22 09:54:58 by sel-abbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
	int		i;
	int		s;

	i = 0;
	nb = 0;
	s = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		if (!ft_isdigit(str[i]) || (nb * s) < INT_MIN || (nb * s) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	count_args(int size, char **av)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < size)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (exit(1), 0);
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
		if (!args[*k])
		{
			ft_free(args);
			ft_free(split);
			exit(1);
		}
		if (!is_valid_number(args[*k]))
		{
			write(2, "Error\n", 6);
			ft_free(args);
			ft_free(split);
			exit(1);
		}
		j++;
		(*k)++;
	}
}

char	**read_input(int ac, char **av)
{
	char	**args;
	char	**split;
	int		count;
	int		i;
	int		k;

	k = 0;
	count = 0;
	count = count_args(ac, av);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (ft_free(args), NULL);
	i = 0;
	while (i <= count)
		args[i++] = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i++], ' ');
		if (!split)
			return (ft_free(args), NULL);
		ft_join(split, args, &k);
		ft_free(split);
	}
	return (args[k] = NULL, args);
}
