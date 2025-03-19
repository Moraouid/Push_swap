CC = cc -g

CFLAGS = -Wall -Wextra -Werror 

SRCS = src/push_swap.c src/reading.c src/handle_error.c src/operations_a.c src/operations_b.c \
	   src/algo_sort.c src/algo_utils_1.c src/algo_utils_2.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) includes/libft/libft.a 

libft:
	make -C includes/libft
clean:
	make -C includes/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C includes/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
