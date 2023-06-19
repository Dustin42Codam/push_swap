/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   halve_group_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 03:37:15 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 22:07:21 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_half_to_stack_a(t_stack *stack, size_t median, size_t group)
{
	while (find_value_b(stack->b, median, top(stack->b)->group))
	{
		if (top(stack->b)->group == group && \
			top(stack->b)->sort_id >= median)
		{
			top(stack->b)->group++;
			push_a(stack, PRINT);
		}
		else
		{
			rotate_b(stack, PRINT);
			stack->regroup++;
		}
	}
}

void	halve_group_b(t_stack *stack)
{
	size_t	group;
	size_t	median;

	check_swap(stack);
	while (top(stack->b) && \
		!check_sort_grp_a(stack->a, top(stack->a)->group) && \
		!check_sort_grp_b(stack->b, top(stack->b)->group))
		push_group_to_a(stack, top(stack->b)->group);
	check_complete_sort(stack);
	if (top(stack->b)->group > 0)
	{
		median = get_median(stack->b, top(stack->b)->group);
		group = top(stack->b)->group;
		push_half_to_stack_a(stack, median, group);
		while (stack->regroup)
		{
			reverse_rotate_b(stack, PRINT);
			stack->regroup--;
		}
		halve_group_a(stack);
	}
	if (check_sort_a(stack) || ft_lstsize(stack->b))
		halve_group_b(stack);
}
