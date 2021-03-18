
NAME = push_swap

CC = clang

#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g

CHECKER_SRC = checker.c bonus.c read_cmds.c read_argv.c \
				execute_cmds.c swap.c push.c rotate.c reverse_rotate.c \
				evaluate_stack.c
PUSH_SWAP_SRC = push_swap.c

OBJ = $(CHECKER_SRC:%.c=%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C libft
	$(CC) $(CHECKER_SRC) libft/libft.a -o checker
	$(CC) $(PUSH_SWAP_SRC) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f checker
	rm -f $(NAME)

re:	fclean all

test:
	gcc -g test.c read_commands.c debug.c libft/libft.a && ./a.out
