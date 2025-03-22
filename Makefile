NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/push_swap.c src/reading.c src/handle_error.c src/operations_a.c \
       src/operations_b.c src/algo_sort.c src/algo_utils_1.c src/algo_utils_2.c \
	   
SRCS_BONUS = src_bonus/checker_bonus.c src_bonus/utils_bonus.c src_bonus/handle_error_bonus.c \
	   src_bonus/op_a_bonus.c src_bonus/op_b_bonus.c src_bonus/reading_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

GNL_DIR = includes/get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(GNL_OBJS) $(LIBFT)

	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(GNL_OBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BONUS) $(GNL_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
