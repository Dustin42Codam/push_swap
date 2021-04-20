# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 22:16:28 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/15 03:13:53 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap checker

BONUS = ./bonus
LIBFT = ./libft
SHARED = ./shared
CHECKER = ./checker_src
PUSH_SWAP = ./push_swap_src

CC = clang

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(word 1, $(NAME)):
	make -C $(LIBFT) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(SHARED) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(PUSH_SWAP) CC=$(CC) CFLAGS=$(CFLAGS)
	cp $(PUSH_SWAP)/$(word 1, $(NAME)) ./$(word 1, $(NAME))

$(word 2, $(NAME)):
	make -C $(LIBFT) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(SHARED) CC=$(CC) CFLAGS=$(CFLAGS)
	make -C $(CHECKER) CC=$(CC) CFLAGS=$(CFLAGS)
	cp $(CHECKER)/$(word 2, $(NAME)) ./$(word 2, $(NAME))

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
	rm -f checker

re: fclean all

f:
	rm -f $(NAME)
	make all