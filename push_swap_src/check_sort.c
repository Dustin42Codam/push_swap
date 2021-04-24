/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 12:09:26 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/23 17:44:49 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_a(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	if (ft_lstsize(tmp) == 1 && tmp != stack->abs_max)
		return (1);
	while (tmp->next)
	{
		if (tmp->next && tmp->next->sort_id != tmp->sort_id - 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_b(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->b;
	if (ft_lstsize(tmp) == 1 && tmp != stack->abs_min)
		return (1);
	while (tmp->next)
	{
		if (tmp->next && tmp->next->sort_id != tmp->sort_id + 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_grp_a(t_list *stack, size_t group)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->group == group && tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_grp_b(t_list *stack, size_t group)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->group == group && tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
