/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median_method.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:39:37 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/20 10:44:00 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

void	push_next_min_median(t_stack *stack)
{
	t_list	*node;
	size_t	dist_top;

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

size_t	get_median(t_stack *stack_data, t_list *stack, size_t group)
{
	size_t	median;
	size_t	i;
	t_list	*tmp;

	i = 0;
	median = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->group == group)
		{
			median += tmp->sort_id;
			i++;
		}
		tmp = tmp->next;
	}
	if (i)
		median = median / i;
	return (median);
}

void	median_method(t_stack *stack, size_t median)
{
	while (ft_lstsize(stack->a) > median)
	{
		if (top(stack->a)->sort_id <= median)
		{
			top(stack->a)->group++;
			push_b(stack, PRINT);
		}
		else
			push_next_min_median(stack);
/* 		if (bottom(stack->a)->sort_id <= median)
		{
			bottom(stack->a)->group++;
			reverse_rotate_a(stack, PRINT);
			continue ;
		}
		if (top(stack->a)->sort_id > median)
			rotate_a(stack, PRINT); */
	}
	// print_stack(stack);
}
/* void	median_method(t_stack *stack, size_t median)
{
	while (ft_lstsize(stack->a) > median)
	{
		if (top(stack->a)->sort_id <= median)
		{
			top(stack->a)->group++;
			push_b(stack, PRINT);
		}
		else
		{
			if (bottom(stack->a)->sort_id <= median)
			{
				bottom(stack->a)->group++;
				reverse_rotate_a(stack, PRINT);
				continue ;
			}
			else
			{
				if (top(stack->a)->sort_id > median)
					rotate_a(stack, PRINT);
			}
		}
		// sleep(1);
	}
		print_stack(stack);
} */
