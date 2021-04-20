/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 13:01:53 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/19 15:03:16 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_data(t_stack *stack)
{
	stack->size_a = ft_lstsize(stack->a);
	stack->size_b = 0;
	stack->median = stack->size_a / 2;

	// return (stack);
}

void	refresh_stack_data(t_stack *stack)
{
	stack->size_a = ft_lstsize(stack->a);
	stack->size_b = ft_lstsize(stack->b);
}