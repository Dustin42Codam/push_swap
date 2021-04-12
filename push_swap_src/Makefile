# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 22:19:12 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/12 20:37:38 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c read_argv.c debug.c

LIBFT = ../libft

SHARED = ../shared

OBJ = $(SRC:%.c=%.o)

ifndef CFLAGS
	CFLAGS = -Wall -Wextra -Werror
endif

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT)
	make -C $(SHARED)
	$(CC) -I $(LIBFT)  $(OBJ) $(SHARED)/stack.a \
		$(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT) -I $(SHARED) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
