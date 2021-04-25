/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/13 18:40:27 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 03:55:46 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_top(t_list *stack)
{
	if (ft_lstsize(stack) < 2)
		return (0);
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

size_t	get_median(t_list *stack, size_t group)
{
	size_t	median;
	size_t	i;
	t_list	*tmp;

	i = 0;
	median = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->group == group)
		{
			median += tmp->sort_id;
			i++;
		}
		tmp = tmp->next;
	}
	if (i)
		median = median / i;
	return (median);
}

size_t	group_size(t_list *lst, size_t group)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		if (lst->group == group)
			i++;
		lst = lst->next;
	}
	return (i);
}
