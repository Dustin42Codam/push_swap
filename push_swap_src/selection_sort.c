/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selection_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/19 12:47:37 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	t_list	*tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	push_min(t_stack *stack, t_list *min)
{
	t_list	*top;

	top = ft_lstlast(stack->a);
	while (top != min)
	{
		rotate_a(stack, PRINT);
		top = ft_lstlast(stack->a);
	}
	push_b(stack, PRINT);
}

int	selection_sort(t_stack *stack)
{
	t_list	*min;

	while (ft_lstsize(stack->a))
	{
		min = find_min(stack->a);
		push_min(stack, min);
	}
	while (ft_lstsize(stack->b))
		push_a(stack, PRINT);
	return (0);
}
