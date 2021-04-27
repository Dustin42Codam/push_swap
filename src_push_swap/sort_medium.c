/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_medium.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 02:03:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 02:04:03 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_next_min(t_stack *stack)
{
	t_list	*node;

	node = min(stack->a);
	enumerate_stack(stack->a);
	if (node->index >= ft_lstsize(stack->a) / 2)
	{
		while (top(stack->a) != node)
			rotate_a(stack, PRINT);
	}
	else
	{
		while (top(stack->a) != node)
			reverse_rotate_a(stack, PRINT);
	}
	push_b(stack, PRINT);
}

static void	check_rotation(t_stack *stack)
{
	if (bottom(stack->a)->content < top(stack->a)->content && \
		bottom(stack->a)->sort_id > stack->half && \
		top(stack->a)->sort_id > stack->half)
		rotate_a(stack, PRINT);
	else if (bottom(stack->a)->content < top(stack->a)->content)
		reverse_rotate_a(stack, PRINT);
}

void	sort_medium(t_stack *stack)
{
	while (check_sort(stack->a))
	{
		check_rotation(stack);
		if (compare_top(stack->a))
			swap_a(stack, PRINT);
		if (top(stack->a)->sort_id <= stack->half && !check_sort(stack->a))
		{
			push_b(stack, PRINT);
			if (ft_lstsize(stack->b) >= 2 && compare_top(stack->b) == 0)
			{
				if (top(stack->b)->content < bottom(stack->b)->content)
					rotate_b(stack, PRINT);
				else if (ft_lstsize(stack->a) >= 2 && compare_top(stack->a))
					swap_a_b(stack, PRINT);
				else
					swap_b(stack, PRINT);
			}
		}
		if (check_sort(stack->a))
			push_next_min(stack);
	}
	while (stack->b)
		push_a(stack, PRINT);
}
