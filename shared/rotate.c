/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 07:12:46 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/14 20:13:51 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_a(t_stack *stack, char mode)
{
	t_list	*last;
	t_list	*second_last;
	int		len;

	len = ft_lstsize(stack->a);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		last = stack->a;
		stack->a = stack->a->next;
		stack->a->next = last;
		stack->a->next->next = 0;
	}
	else
	{
		last = ft_lstlast(stack->a);
		second_last = stack->a;
		while (second_last->next != last)
			second_last = second_last->next;
		ft_lstadd_front(&stack->a, last);
		second_last->next = 0;
	}
	if (mode == PRINT)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack *stack, char mode)
{
	t_list	*last;
	t_list	*second_last;
	int		len;

	len = ft_lstsize(stack->b);
	if (len <= 1)
		return ;
	else if (len == 2)
	{
		last = stack->b;
		stack->b = stack->b->next;
		stack->b->next = last;
		stack->b->next->next = 0;
	}
	else
	{
		last = ft_lstlast(stack->b);
		second_last = stack->b;
		while (second_last->next != last)
			second_last = second_last->next;
		ft_lstadd_front(&stack->b, last);
		second_last->next = 0;
	}
	if (mode == PRINT)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_a_b(t_stack *stack, char mode)
{
	rotate_a(stack, NO_PRINT);
	rotate_b(stack, NO_PRINT);
	if (mode == PRINT)
		ft_putstr_fd("rr\n", 1);
}
