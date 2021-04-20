/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/20 08:06:00 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_top(t_list *stack)
{
	return (top(stack)->content > get(stack, ft_lstsize(stack) - 2)->content);
}

void	enumerate_stack(t_list *stack)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = stack;
	while (node)
	{
		node->index = i;
		node->check = 0;
		node->group = 0;
		node = node->next;
		i++;
	}
}
