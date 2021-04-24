/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/22 19:08:29 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_top(t_list *stack)
{
	if (ft_lstsize(stack) < 2)
		return (0);
	return (top(stack)->content > get(stack, ft_lstsize(stack) - 2)->content);
}

int	compare_top_sort_id_a(t_stack *stack)
{
	if (ft_lstsize(stack->a) < 2)
		return (0);
	return (top(stack->a)->sort_id == get(stack->a, ft_lstsize(stack->a) - 2)->sort_id - 1);
}

int	compare_top_sort_id_b(t_stack *stack)
{
	if (ft_lstsize(stack->b) < 2)
		return (0);
	return (top(stack->b)->sort_id == get(stack->b, ft_lstsize(stack->b) - 2)->sort_id + 1);
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

void	index_stack(t_list *stack)
{
	t_list	*node;
	size_t	i;

	i = 0;
	node = stack;
	while (node)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}
