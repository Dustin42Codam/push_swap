/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   median_method.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:39:37 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/24 19:03:16 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

void	push_next_min_median_a(t_stack *stack)
{
	t_list	*node;
	size_t	dist_top;

	node = min(stack->a);
	index_stack(stack->a);
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
	top(stack->a)->group++;
	push_b(stack, PRINT);
}

void	push_next_min_median_b(t_stack *stack)
{
	t_list	*node;
	size_t	dist_top;

	node = min(stack->b);
	index_stack(stack->b);
	if (node->index >= ft_lstsize(stack->b) / 2)
	{
		while (top(stack->b) != node)
			rotate_b(stack, PRINT);
	}
	else
	{
		while (top(stack->b) != node)
			reverse_rotate_b(stack, PRINT);
	}
	top(stack->b)->group++;
	push_a(stack, PRINT);
}

void	push_next_max_median_b(t_stack *stack)
{
	t_list	*node;
	size_t	dist_top;

	node = max(stack->b);
	index_stack(stack->b);
	if (node->index >= ft_lstsize(stack->b) / 2)
	{
		while (top(stack->b) != node)
			rotate_b(stack, PRINT);
	}
	else
	{
		while (top(stack->b) != node)
			reverse_rotate_b(stack, PRINT);
	}
	top(stack->b)->group++;
	push_a(stack, PRINT);
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

size_t	group_size(t_list *lst, size_t group)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		if (lst->group == group)
			i++;
		lst = lst->next;
	}
	return (i);
}

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

int		find_value_b(t_list *stack, size_t value, size_t group)
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

int		find_value_a(t_list *stack, size_t value, size_t group)
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

void	median_method_a(t_stack *stack, size_t median, size_t group)
{
	// if (check_sort(stack->a) == 0)
		// return ;
	printf("method_a:\n");
	while (find_value_a(stack->a, median, group))
	{
		if (top(stack->a)->group == group && top(stack->a)->sort_id <= median)
		{
			top(stack->a)->group++;
			push_b(stack, PRINT);
		}
		else
			rotate_a(stack, PRINT);
	}
	while (bottom(stack->a)->group == group && group != 0)
		reverse_rotate_a(stack, PRINT);
	if ((top(stack->b)->sort_id + 1 == get(stack->b, ft_lstsize(stack->b) - 2)->sort_id) && \
		top(stack->b)->group == get(stack->b, ft_lstsize(stack->b) - 2)->group)
		swap_b(stack, PRINT);
	if ((top(stack->a)->sort_id - 1 == get(stack->a, ft_lstsize(stack->a) - 2)->sort_id) && \
		top(stack->a)->group == get(stack->a, ft_lstsize(stack->a) - 2)->group)
		swap_a(stack, PRINT);
	if (!check_sort_grp_a(stack->a, top(stack->a)->group) && \
		!check_sort_grp_b(stack->b, top(stack->b)->group))
		push_group(stack, group);
	while (check_sort(stack->a) && top(stack->a)->sort_id == top(stack->b)->sort_id + 1)
		push_b(stack, PRINT);
	// if (!check_sort_grp_a(stack->a, group) && !check_sort_grp_b(stack->b, group + 1))
	// 	push_group(stack, group);
	print_stacks_ps(stack);
}

void	median_method_b(t_stack *stack, size_t median, size_t group)
{
	printf("method_b:\n");
	while (find_value_b(stack->b, median, group))
	{
		if (top(stack->b)->group == group && top(stack->b)->sort_id > median)
		{
			top(stack->b)->group++;
			push_a(stack, PRINT);
		}
		else
			rotate_b(stack, PRINT);
			// push_next_max_median_b(stack);
	}
	while (bottom(stack->b)->group == group && group != 1)
		reverse_rotate_b(stack, PRINT);
	if (!check_sort_grp_b(stack->b, group) && !check_sort_grp_a(stack->a, group - 1))
		push_group(stack, group);
	print_stacks_ps(stack);
}

void	median_method_a2(t_stack *stack, size_t median, size_t group)
{
	if (ft_lstsize(stack->a) <= 2)
		return ;
	// printf("method_a2:\n");
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
	// print_stacks_ps(stack);
	median_method_a2(stack, get_median(stack, stack->a, group), group);
}

void	median_method_b2(t_stack *stack, size_t median, size_t group)
{
	if (top(stack->b)->group == 3)
		return ;
	if (group_size(stack->b, top(stack->b)->group) == 2 && compare_top_sort_id_b(stack) == 0)
		swap_b(stack, PRINT);
	if (!check_sort_grp_b(stack->b, top(stack->b)->group))
	{
		push_group(stack, top(stack->b)->group);
		// print_stacks_ps(stack);
		// return ;
	}
	while (find_value_b(stack->b, median, group))
	{
		if (top(stack->b)->group == group && top(stack->b)->sort_id > median)
		{
			top(stack->b)->group++;
			push_a(stack, PRINT);
		}
		else
			rotate_b(stack, PRINT);
			// push_next_max_median_b(stack);
	}
	print_stacks_ps(stack);
	median = get_median(stack, stack->b, top(stack->b)->group);
	printf("grp:%ld top_grp:%ld\nmedian: %ld", stack->group_id, top(stack->b)->group, median);
	median_method_b2(stack, get_median(stack, stack->b, group), group);
}


void	median_method(t_stack *stack, size_t median, size_t group)
{
	// print_stacks_ps(stack);

	median_method_a2(stack, get_median(stack, stack->a, group), group);
	chonk_b(stack);
	exit(0);
	median_method_b2(stack, get_median(stack, stack->a, group), group);
	while (ft_lstsize(stack->a) > 2)
	{
		median_method_a2(stack, get_median(stack, stack->a, group), group);
	}
		// median_method_b2(stack, get_median(stack, stack->b, group), group);
	// while (ft_lstsize(stack->b) > 2)
	exit(0);

	// for (int group = 0; group < 2; group++)
	while (group < 1)
	{
		median_method_a(stack, get_median(stack, stack->a, group), group);
		group++;
		median_method_b(stack, get_median(stack, stack->b, group), group);
		group++;
	}
}
