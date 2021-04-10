# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkrecisz <dkrecisz@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/10 23:12:08 by dkrecisz      #+#    #+#                  #
#    Updated: 2021/04/10 23:58:48 by dkrecisz      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC =	checker.c bonus.c read_cmds.c read_argv.c \
		execute_cmds.c evaluate_stack.c

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
	$(CC) $(OBJ) $(SHARED)/stack.a $(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
