/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:37:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/08 20:50:31 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/include/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

#endif
