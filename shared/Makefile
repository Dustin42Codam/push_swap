# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 23:45:26 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/25 23:49:21 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libstack.a

SRC =	push.c swap.c rotate.c reverse_rotate.c \
		get.c top.c bottom.c min.c max.c

OBJ = $(SRC:%.c=%.o)

LIBFT = ../libft

CFLAGS = -Wall -Wextra -Werror

CC = clang

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
