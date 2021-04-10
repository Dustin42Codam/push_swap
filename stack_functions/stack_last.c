/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_last.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 22:11:16 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/29 18:33:01 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
