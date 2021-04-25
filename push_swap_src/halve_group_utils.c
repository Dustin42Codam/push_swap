/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   halve_group_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 03:33:14 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 05:41:11 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	merge_groups(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
}

void	check_swap_a(t_stack *stack)
{
	if (check_sort_grp_a(stack->a, top(stack->a)->group))
		swap_a(stack, PRINT);
}

void	check_swap_b(t_stack *stack)
{
	if (check_sort_grp_b(stack->b, top(stack->b)->group))
		swap_b(stack, PRINT);
}

void	check_swap(t_stack *stack)
{
	if (group_size(stack->b, top(stack->b)->group) == 2)
		check_swap_b(stack);
	if (group_size(stack->a, top(stack->a)->group) == 2)
		check_swap_a(stack);
}

void	check_complete_sort(t_stack *stack)
{
	if (check_sort_a(stack) == 0 && ft_lstsize(stack->b) == 0)
	{
		clean_up(stack, NO_ERROR);
		exit(0);
	}
}
