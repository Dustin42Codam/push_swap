
NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

CHECKER_SRC = checker.c debug.c read_cmds.c read_args.c \
				execute_cmds.c swap.c

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C libft
	$(CC) $(CHECKER_SRC) libft/libft.a -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f checker
	rm -f $(NAME)

re:	fclean all

test:
	gcc -g test.c read_commands.c debug.c libft/libft.a && ./a.out
