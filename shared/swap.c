/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 07:37:09 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/14 06:44:19 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/** 
 *  Idea:
 *	0. |A|->|B|->|C|->|0| 
 *	1. |A|->|B|<->|C|
 *	2. |A|->|C|<->|B|
 *	3. |A|->|C|->|B|->|0|
 * 
 * **/

void	swap_a(t_stack *stack)
{
	t_list	*tmp;
	int		len;

	tmp = stack->a;
	len = ft_lstsize(stack->a);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		stack->a = stack->a->next;
		stack->a->next = tmp;
		stack->a->next->next = 0;
	}
	else
	{
		while (tmp->next->next->next != 0)
			tmp = tmp->next;
		tmp->next->next->next = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->next->next = 0;
	}
}

void	swap_b(t_stack *stack)
{
	t_list	*tmp;
	int		len;

	tmp = stack->b;
	len = ft_lstsize(stack->b);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		stack->b = stack->b->next;
		stack->b->next = tmp;
		stack->b->next->next = 0;
	}
	else
	{
		while (tmp->next->next->next != 0)
			tmp = tmp->next;
		tmp->next->next->next = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->next->next = 0;
	}
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
