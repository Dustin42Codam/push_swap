/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:37:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/10 22:56:15 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

# define COLORS 1
# define DEBUG 2
# define READ_FILE 4
# define SLOMO 8

# include "../libft/include/libft.h"
# include "../shared/stack.h"
# include <stdio.h>

typedef struct s_flags
{
	unsigned int	bitfield : 5;
}	t_flags;

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

int		read_argv(int ac, char *av[], t_stack *stack, t_flags *flags);
char	**read_cmds(void);
int		validate_cmds(t_cmd *cmd);
void	execute_cmds(t_stack *stack, t_cmd cmd, t_flags flags);
int		count_cmds(char **list);
void	evaluate_stack(t_stack *stack);

#endif
