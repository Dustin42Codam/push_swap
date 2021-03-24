/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 07:52:32 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/14 08:18:36 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_list	*tmp;
	t_list	*head;
	int		len;

	len = ft_lstsize(stack->a);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		stack->a->next = tmp;
		stack->a->next->next = 0;
	}
	else
	{
		head = stack->a;
		tmp = stack->a->next;
		ft_lstadd_back(&stack->a, head);
		head->next = 0;
		stack->a = tmp;
	}
}

void	reverse_rotate_b(t_stack *stack)
{
	t_list	*tmp;
	t_list	*head;
	int		len;

	len = ft_lstsize(stack->b);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		stack->b->next = tmp;
		stack->b->next->next = 0;
	}
	else
	{
		head = stack->b;
		tmp = stack->b->next;
		ft_lstadd_back(&stack->b, head);
		head->next = 0;
		stack->b = tmp;
	}
}

void	reverse_rotate_a_b(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
