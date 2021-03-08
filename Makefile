
NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C libft
	$(CC) checker.c libft/libft.a -o checker

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f checker
	rm -f $(NAME)

re:	fclean all
