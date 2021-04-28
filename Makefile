
SRC_CHK = checker.c init_cmds.c read_cmds.c read_argv.c \
		execute_cmds.c evaluate_stack.c validate_cmds.c \
		bonus.c print_help_bonus.c
	  
SRC_PS = push_swap.c read_argv.c init_stack_data.c \
		sort.c sort_utils_1.c sort_utils_2.c \
		check_sort.c \
		halve_group_a.c halve_group_b.c halve_group_utils.c \
		sort_easy.c sort_medium.c sort_hardcore.c 

OBJ_CHK = $(SRC_CHK:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)

SRCDIR_SHARE = shared
SRCDIR_CHK = src_checker
OBJDIR_CHK = obj_checker
SRCDIR_PS = src_push_swap
OBJDIR_PS = obj_push_swap
LIBDIR = libft
SHAREDIR = shared

SRCS_CHK = $(addprefix $(SRCDIR_CHK)/, $(SRC_CHK))
OBJS_CHK = $(addprefix $(OBJDIR_CHK)/, $(OBJ_CHK))

SRCS_PS = $(addprefix $(SRCDIR_PS)/, $(SRC_PS))
OBJS_PS = $(addprefix $(OBJDIR_PS)/, $(OBJ_PS))

LIBS = -L $(LIBDIR) -lft -L $(SHAREDIR) -lstack
HEADER = -I includes -I $(LIBDIR) -I $(SHAREDIR)

CC = clang
CFLAGS = -c -Wall -Wextra -Werror

NAME = checker push_swap
NAME_CHK = checker
NAME_PS = push_swap

.PHONY: all clean fclean re

all: $(NAME_CHK) $(NAME_PS)

# Compiling checker
$(word 1, $(NAME)): $(OBJS_CHK)
	@make bonus -C $(LIBDIR)
	@make -C $(SHAREDIR)
	@$(CC) $(OBJS_CHK) $(HEADER) $(LIBS) -o $@
	@echo "[checker is ready!]"

$(OBJS_CHK): $(OBJDIR_CHK)/%.o: $(SRCDIR_CHK)/%.c
	@mkdir -p $(OBJDIR_CHK)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

# Compiling push_swap
$(word 2, $(NAME)): $(OBJS_PS)
	@make bonus -C $(LIBDIR)
	@make -C $(SHAREDIR)
	@$(CC) $(OBJS_PS) $(HEADER) $(LIBS) -o $@
	@echo "[push_swap is ready!]"

$(OBJS_PS): $(OBJDIR_PS)/%.o: $(SRCDIR_PS)/%.c
	@mkdir -p $(OBJDIR_PS)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

clean:
	@rm -rf $(OBJDIR_CHK)
	@rm -rf $(OBJDIR_PS)
	@make -C $(LIBDIR) clean
	@make -C $(SHAREDIR) clean
	@echo "[cleaned up object files.]"

fclean: clean
	@rm -rf $(OBJDIR_CHK)
	@rm -rf $(OBJDIR_PS)
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_PS)
	@make -C $(LIBDIR) fclean
	@make -C $(SHAREDIR) fclean
	@echo "[everything cleaned up]"

re: fclean all

check: check_leak check_error check_ko check_ok check_pw

check_leak:
	bash test/leaks.sh test/

check_error: all
	./checker a 2>&1 | cat -e
	./checker 1 1 2>&1 | cat -e
	./checker 2147483649 2>&1 | cat -e
	./checker 2>&1 | cat -e
	echo "swap" | ./checker "1 2" 2>&1 | cat -e
	echo "sa  " | ./checker "1 2" 2>&1 | cat -e
	echo "  sa" | ./checker "1 2" 2>&1 | cat -e
	./checker -g 2>&1 | cat -e
	./checker -catgv 2>&1 | cat -e
	./push_swap a 2>&1 | cat -e
	./push_swap 1 1 2>&1 | cat -e
	./push_swap -2147483649 2>&1 | cat -e
	./push_swap 2>&1 | cat -e

check_ko: $(NAME)
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	echo "sa\npb\nrrr" | ./checker "3 2 5 1"

check_ok: $(NAME) $(NAME_PW)
	echo "\0" | ./checker 0 1 2
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2
	echo "sa" | ./checker 1 0 2

check_pw:
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	ARG="2 1 0"; ./push_swap $$ARG | ./checker $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
