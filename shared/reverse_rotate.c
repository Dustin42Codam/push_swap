/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 07:52:32 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:16:41 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate_a(t_stack *stack, char mode)
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
	if (mode == PRINT)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack *stack, char mode)
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
	if (mode == PRINT)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_a_b(t_stack *stack, char mode)
{
	reverse_rotate_a(stack, NO_PRINT);
	reverse_rotate_b(stack, NO_PRINT);
	if (mode == PRINT)
		ft_putstr_fd("rrr\n", 1);
}
