/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/19 13:01:53 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 01:59:19 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_data(t_stack *stack, size_t stack_len)
{
	stack->half = stack_len / 2;
	stack->abs_max = max(stack->a);
	stack->abs_min = min(stack->a);
	stack->regroup = 0;
}
