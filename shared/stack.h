/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/10 22:51:07 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/23 06:27:26 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include <stddef.h>

# define PRINT 1
# define NO_PRINT 0

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_list	*abs_max;
	t_list	*abs_min;
	size_t	median;
	size_t	size_a;
	size_t	size_b;
	size_t	group_id;
	size_t	regroup;
/* 	
	size_t	median_a;
	size_t	median_b;
	size_t	min;
	size_t	min_a;
	size_t	min_b;
	size_t	max;
	size_t	max_a;
	size_t	max_b;
	size_t	op; */
	// t_list	(*get)(t_list *stack, size_t index);
	// void	(*print)(void);
}	t_stack;

void	swap_a(t_stack *stack, char mode);
void	swap_b(t_stack *stack, char mode);
void	swap_a_b(t_stack *stack, char mode);
void	push_a(t_stack *stack, char mode);
void	push_b(t_stack *stack, char mode);
void	rotate_a(t_stack *stack, char mode);
void	rotate_b(t_stack *stack, char mode);
void	rotate_a_b(t_stack *stack, char mode);
void	reverse_rotate_a(t_stack *stack, char mode);
void	reverse_rotate_b(t_stack *stack, char mode);
void	reverse_rotate_a_b(t_stack *stack, char mode);

t_list	*get(t_list *stack, size_t index);
t_list	*top(t_list *stack);
t_list	*bottom(t_list *stack);

t_list	*min(t_list *stack);
t_list	*max(t_list *stack);

int		isupper_half(t_list *stack);
t_list	*get_next_min(t_list *stack);
// void	print(void);

#endif
