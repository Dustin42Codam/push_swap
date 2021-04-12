# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 23:45:26 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/12 19:19:01 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = stack.a

SRC = push.c swap.c rotate.c reverse_rotate.c

OBJ = $(SRC:%.c=%.o)

LIBFT = ../libft

ifndef CFLAGS
	CFLAGS = -Wall -Wextra -Werror
endif

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
