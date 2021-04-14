/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:24:52 by dkrecisz      ########   odam.nl         */
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
