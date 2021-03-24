
NAME = push_swap

CC = clang

#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g

SRC = push_swap.c read_argv.c

OBJ = $(SRC:%.c=%.o)

LIBFT = ./libft
CHECKER = ./checker_src

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT)
	make -C $(CHECKER)
	mv $(CHECKER)/checker .
	$(CC) $(SRC) $(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(CHECKER)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f checker
	rm -f $(NAME)

re:	fclean all
