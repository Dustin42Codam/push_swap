/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   evaluate_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/14 11:06:16 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/18 09:16:55 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	evaluate_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	if (ft_lstsize(stack->b))
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		tmp = tmp->next;
	}
	ft_putstr_fd("OK\n", 1);
}
