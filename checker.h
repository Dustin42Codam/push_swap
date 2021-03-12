/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:37:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 22:53:41 by dkrecisz      ########   odam.nl         */
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

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

int		read_arguments(int argc, char *argv[], t_stack *stack);
char	**read_commands(void);
int		validate_commands(char **cmds);
/** Debug function - delete later **/
void	print_all(t_list *list, char **cmds);

#endif
