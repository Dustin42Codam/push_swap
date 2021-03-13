/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:37:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 05:53:04 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/include/libft.h"

# include <fcntl.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

typedef void		t_execute(void);

typedef struct		s_jump
{
	t_execute	*function[3];
} t_jump;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_command
{
	__uint8_t	id;
	__uint8_t	count;
	char		**list;
	const char	*pool[];
}	t_command;

int		read_arguments(int argc, char *argv[], t_stack *stack);
char	**read_commands(void);
int		validate_commands(char **cmds);
/** Debug function - delete later **/
void	print_all(t_list *list, char **cmds);
void	execute_commands(t_stack *stack, char **commands);

#endif
