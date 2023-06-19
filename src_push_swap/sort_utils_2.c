/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 02:29:04 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 02:29:39 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_group_to_a(t_stack *stack, size_t group)
{
	while (top(stack->b) && top(stack->b)->group == group)
	{
		top(stack->b)->group = top(stack->a)->group;
		push_a(stack, PRINT);
	}
}

void	push_group(t_stack *stack, size_t group)
{
	if (group % 2)
	{
		while (top(stack->b)->group == group)
		{
			top(stack->b)->group = top(stack->a)->group;
			push_a(stack, PRINT);
		}
	}
	else
	{
		while (top(stack->a)->group == group)
		{
			top(stack->a)->group = top(stack->b)->group;
			push_b(stack, PRINT);
		}
	}
}

int	find_value_b(t_list *stack, size_t value, size_t group)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->group == group && tmp->sort_id >= value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_value_a(t_list *stack, size_t value, size_t group)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->group == group && tmp->sort_id < value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
