/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 01:17:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:18:13 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * 		Idea:
 *	0.	|A|->|1|->|2|->|3|->|0|			|B|->|4|->|5|->|6|->|0|
 *	1.	|A|->|1|->|2|->|3|->|0|			|B|->|4|->|5|->|0|
 *									 	[last_b:] |6|->|0|
 *	2.	|A|->|1|->|2|->|3|->|6|->|0|	|B|->|4|->|5|->|0|
 *
 * **/

void	push_a(t_stack *stack, char mode)
{
	t_list	*last_b;
	t_list	*tmp;
	int		len_b;

	len_b = ft_lstsize(stack->b);
	if (len_b == 0)
		return ;
	else if (len_b == 1)
	{
		last_b = ft_lstlast(stack->b);
		ft_lstadd_back(&stack->a, last_b);
		stack->b = 0;
	}
	else
	{
		last_b = ft_lstlast(stack->b);
		tmp = stack->b;
		while (tmp->next->next != 0)
			tmp = tmp->next;
		tmp->next = 0;
		ft_lstadd_back(&stack->a, last_b);
	}
	if (mode == PRINT)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack *stack, char mode)
{
	t_list	*last_a;
	t_list	*tmp;
	int		len_a;

	len_a = ft_lstsize(stack->a);
	if (len_a == 0)
		return ;
	else if (len_a == 1)
	{
		last_a = ft_lstlast(stack->a);
		ft_lstadd_back(&stack->b, last_a);
		stack->a = 0;
	}
	else
	{
		last_a = ft_lstlast(stack->a);
		tmp = stack->a;
		while (tmp->next->next != 0)
			tmp = tmp->next;
		tmp->next = 0;
		ft_lstadd_back(&stack->b, last_a);
	}
	if (mode == PRINT)
		ft_putstr_fd("pb\n", 1);
}
