
NAME = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

CHECKER_SRC = checker.c bonus.c read_cmds.c read_argv.c \
				execute_cmds.c swap.c push.c rotate.c reverse_rotate.c \
				evaluate_stack.c
PUSH_SWAP_SRC = push_swap.c

LIBFT = ../libft

OBJ = $(CHECKER_SRC:%.c=%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT)
	$(CC) $(CHECKER_SRC) $(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re:	fclean all
