/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   selection_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:25:40 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

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
