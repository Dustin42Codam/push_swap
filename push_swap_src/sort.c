/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 00:21:11 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/20 10:40:41 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	check_sort(t_stack *stack, char type)
static int	check_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}

/* 	if (type == 'A')
	{
		tmp = stack->a;
		while (tmp->next)
		{
			if (tmp->content < tmp->next->content)
				return (1);
			tmp = tmp->next;
		}
	}
	else if (type == 'B')
	{
		tmp = stack->b;
		while (tmp->next)
		{
			if (tmp->content > tmp->next->content)
				return (1);
			tmp = tmp->next;
		}
	} */
	return (0);
}

static void	sort_three(t_stack *stack, t_list *stack_type)
{
	if (stack_type == stack->a)
	{
		if (stack->a->sort_id == ft_lstsize(stack->a))
			return (ft_putstr_fd("sa\n", 1));
		if (stack->a->next->sort_id == ft_lstsize(stack->a))
			reverse_rotate_a(stack, PRINT);
		else if (stack->a->next->next->sort_id == ft_lstsize(stack->a))
			rotate_a(stack, PRINT);
		if (stack->a->next->sort_id < stack->a->next->next->sort_id)
			swap_a(stack, PRINT);
	}
	else
	{
		if (stack->b->sort_id == ft_lstsize(stack->b))
			return (ft_putstr_fd("sb\n", 1));
		if (stack->b->next->sort_id == ft_lstsize(stack->b))
			reverse_rotate_a(stack, PRINT);
		else if (stack->b->next->next->sort_id == ft_lstsize(stack->b))
			rotate_a(stack, PRINT);
		if (stack->b->next->sort_id < stack->b->next->next->sort_id)
			swap_a(stack, PRINT);
	}
}

static void	push_next_min(t_stack *stack)
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

static void	sort_small_input(t_stack *stack)
{
	while (check_sort(stack->a))
	{
		if (bottom(stack->a)->content < top(stack->a)->content && 
			bottom(stack->a)->sort_id > stack->median &&
			top(stack->a)->sort_id > stack->median)
			rotate_a(stack, PRINT);
		else if (bottom(stack->a)->content < top(stack->a)->content)
			reverse_rotate_a(stack, PRINT);
		if (compare_top(stack->a))
			swap_a(stack, PRINT);
		if (top(stack->a)->sort_id <= stack->median && !check_sort(stack->a))
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

static void	sort_medium_input(t_stack *stack)
{
	while (check_sort(stack->a))
	{
		if (bottom(stack->a)->content < top(stack->a)->content && 
			bottom(stack->a)->sort_id > stack->median &&
			top(stack->a)->sort_id > stack->median)
			rotate_a(stack, PRINT);
		else if (bottom(stack->a)->content < top(stack->a)->content)
			reverse_rotate_a(stack, PRINT);
		if (compare_top(stack->a))
			swap_a(stack, PRINT);
		if (top(stack->a)->sort_id <= stack->median && !check_sort(stack->a))
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
		// if (check_sort(stack->a))
			// push_next_median(stack);
	}
	while (stack->b)
		push_a(stack, PRINT);
}

void	sort(t_stack *stack)
{
	init_stack_data(stack);
	if (stack->size_a == 1 || check_sort(stack->a) == 0)
		return ;
	else if (stack->size_a == 2)
	{
		if (top(stack->a) > bottom(stack->a))
			return (ft_putstr_fd("sa\n", 1));
	}
	else if (stack->size_a == 3)
		sort_three(stack, stack->a);
/* 	else if (stack->size_a >= 4 && stack->size_a < 100)
		sort_small_input(stack);
	else if (stack->size_a >= 100 && stack->size_a < 500)
		sort_medium_input(stack); */
	else if (stack->size_a >= 10 && stack->size_a < 500)
		median_method(stack, get_median(stack, stack->a, 0));
	// printf("median:\t%ld\n", get_median(stack, stack->a, 0));
	// else
		// sort_ten(stack);
}
