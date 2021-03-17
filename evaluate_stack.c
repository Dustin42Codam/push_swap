/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluate_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 11:06:16 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/17 23:23:42 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	evaluate_stack(t_stack *stack)
{
	if (ft_lstsize(stack->b))
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while (stack->a->next)
	{
		if (stack->a->content < stack->a->next->content)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		stack->a = stack->a->next;
	}
	ft_putstr_fd("OK\n", 1);
}
