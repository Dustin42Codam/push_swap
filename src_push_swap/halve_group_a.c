/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   halve_group_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 03:30:49 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 05:04:31 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_half_to_stack_b(t_stack *stack, size_t median, size_t group)
{
	while (find_value_a(stack->a, median, group))
	{
		if (top(stack->a)->group == group && \
			top(stack->a)->sort_id < median)
		{
			top(stack->a)->group++;
			push_b(stack, PRINT);
		}
		else
		{
			rotate_a(stack, PRINT);
			stack->regroup++;
		}
	}
}

void	halve_group_a(t_stack *stack)
{
	size_t	group;
	size_t	median;

	check_swap(stack);
	if (check_sort_a(stack) == 0)
		return (merge_groups(stack->a));
	while (!check_sort_grp_a(stack->a, top(stack->a)->group) && \
		!check_sort_grp_b(stack->b, top(stack->b)->group))
		push_group_to_a(stack, top(stack->b)->group);
	if (top(stack->a)->group > 0)
	{
		median = get_median(stack->a, top(stack->a)->group);
		group = top(stack->a)->group;
		push_half_to_stack_b(stack, median, group);
		while (stack->regroup)
		{
			reverse_rotate_a(stack, PRINT);
			stack->regroup--;
		}
		halve_group_a(stack);
	}
	halve_group_b(stack);
}
