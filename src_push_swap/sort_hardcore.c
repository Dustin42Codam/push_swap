/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_hardcore.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:39:37 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 03:58:49 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_a(t_stack *stack, size_t median, size_t group)
{
	if (ft_lstsize(stack->a) <= 2)
		return ;
	while (find_value_a(stack->a, median, group))
	{
		if (top(stack->a)->group == group && top(stack->a)->sort_id < median)
		{
			top(stack->a)->group = stack->group_id;
			push_b(stack, PRINT);
		}
		else
			rotate_a(stack, PRINT);
	}
	stack->group_id++;
	divide_a(stack, get_median(stack->a, group), group);
}

void	sort_hardcore(t_stack *stack)
{
	divide_a(stack, get_median(stack->a, 0), 0);
	halve_group_b(stack);
}
