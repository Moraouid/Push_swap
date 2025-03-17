#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void	ft_join(char **split, char **args, int *k);
char	**read_input(int ac, char **av);
int	count_args(int size, char **av);
void	ft_free(char **str);
int	check_args(char **args);
int	check_duplicates(char **args);
int	is_sorted(t_list *stack);

#endif