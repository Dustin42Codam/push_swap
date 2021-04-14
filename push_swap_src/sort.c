/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 00:21:11 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:28:00 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	sort_three(t_stack *stack)
{
	if (stack->a->sort_id == 3)
		return (ft_putstr_fd("sa\n", 1));
	if (stack->a->next->sort_id == 3)
		reverse_rotate_a(stack, PRINT);
	else if (stack->a->next->next->sort_id == 3)
		rotate_a(stack, PRINT);
	if (stack->a->next->sort_id < stack->a->next->next->sort_id)
		swap_a(stack, PRINT);
}

/* static void	sort_five(t_stack *stack, size_t size)
{
	t_list	*min;

	while (ft_lstsize(stack->a) > 3)
	{
		min = find_min(stack->a);
		if (min->index <= 2)
		{
			while (ft_lstlast(stack->a) != min)
			{
				ft_putstr_fd("ra\n", 1)
			}
		}
		push_a(stack);
		ft_putstr_fd("pa\n", 1);
	}
	sort_three(stack);
	while (ft_lstsize(stack->b))
	{
		push_b(stack);
		ft_putstr_fd("pb\n", 1);
	}
} */

void	sort(t_stack *stack)
{
	size_t	size;

	size = ft_lstsize(stack->a);
	if (size == 1 || check_sort(stack) == 0)
		return ;
	else if (size == 2)
	{
		if (stack->a->content < stack->a->next->content)
			ft_putstr_fd("sa\n", 1);
	}
	else if (size == 3)
		sort_three(stack);
	// else if (size >= 4 && size <= 5)
		// sort_five(stack, size);
	// else
		// sort_ten(stack);
	check_sort(stack);
}
