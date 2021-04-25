/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 00:21:11 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 03:57:40 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	size_t	stack_len;

	stack_len = ft_lstsize(stack->a);
	init_stack_data(stack, stack_len);
	if (stack_len == 1 || check_sort(stack->a) == 0)
		return ;
	else if (stack_len == 2)
	{
		if (top(stack->a)->content > bottom(stack->a)->content)
			return (ft_putstr_fd("sa\n", 1));
	}
	else if (stack_len == 3)
		sort_easy(stack);
	else if (stack_len >= 4 && stack_len <= 10)
		sort_medium(stack);
	else
	{
		stack->group_id = 1;
		sort_hardcore(stack);
	}
}
