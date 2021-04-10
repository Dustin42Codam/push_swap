# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 22:16:28 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/10 22:23:10 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ./libft
CHECKER = ./checker_src
PUSH_SWAP = ./push_swap

all: $(NAME)

$(NAME):
	make -C $(CHECKER)
	make -C $(PUSH_SWAP)

clean:
	make clean -C $(LIBFT)
	make clean -C $(CHECKER)
	make clean -C $(PUSH_SWAP)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(CHECKER)
	make fclean -C $(PUSH_SWAP)

re: fclean re

push_swap:
	make -C $(PUSH_SWAP)

checker:
	make -C $(CHECKER)
