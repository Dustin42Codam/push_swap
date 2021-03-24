/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 21:28:09 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/24 21:47:22 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

# include "libft/include/libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

int	read_argv(int ac, char *av[], t_stack *stack);

#endif
