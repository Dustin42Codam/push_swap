# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 22:19:12 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/20 09:46:35 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	push_swap.c read_argv.c debug.c selection_sort.c sort.c \
		init_stack_data.c sort_utils.c bonus.c

LIBFT = ../libft

SHARED = ../shared

OBJ = $(SRC:%.c=%.o)

ifndef CFLAGS
	CFLAGS = -Wall -Wextra
endif

CC = gcc

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
