/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/10 22:51:07 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/12 18:57:52 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "include/libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

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

#endif
