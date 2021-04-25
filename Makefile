# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 22:16:28 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/25 05:46:53 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap checker

LIBFT = ./libft
SHARED = ./shared
CHECKER = ./checker_src
PUSH_SWAP = ./push_swap_src

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:
	make -C $(LIBFT) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(SHARED) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(CHECKER) CC=$(CC) CFLAGS=$(CFLAGS)
	cp $(CHECKER)/checker .
	make -C $(PUSH_SWAP) CC=$(CC) CFLAGS=$(CFLAGS)
	cp $(PUSH_SWAP)/push_swap .

clean:
	make clean -C $(LIBFT)
	make clean -C $(SHARED)
	make clean -C $(CHECKER)
	make clean -C $(PUSH_SWAP)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(SHARED)
	make fclean -C $(CHECKER)
	make fclean -C $(PUSH_SWAP)
	rm -f $(NAME)

re: fclean all
