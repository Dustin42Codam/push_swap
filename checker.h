/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:37:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/14 07:59:44 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/include/libft.h"

# include <fcntl.h>
//Delete later
# include <stdio.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_cmd
{
	int			*id;
	int			count;
	char		**list;
}	t_cmd;

typedef void	t_function(t_stack *stack);

typedef struct s_jump
{
	t_function	*table[11];
}	t_jump;

int		read_args(int argc, char *argv[], t_stack *stack);
char	**read_cmds(void);
int		validate_cmds(t_cmd *cmd);
void	execute_cmds(t_stack *stack, t_cmd cmd);
int		count_cmds(char **list);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_a_b(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_a_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_a_b(t_stack *stack);

/** Debug function - delete later **/
void	print_all(t_stack *stack, char **cmds);

#endif
