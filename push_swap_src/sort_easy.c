/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_easy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 02:12:37 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 02:12:47 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_easy(t_stack *stack)
{
	if (stack->a->sort_id == 3)
		return (ft_putstr_fd("sa\n", 1));
	if (stack->a->next->sort_id == 3)
		reverse_rotate_a(stack, PRINT);
	else if (stack->a->next->next->sort_id == 3)
		rotate_a(stack, PRINT);
	if (stack->a->next->sort_id < stack->a->next->next->sort_id)
		swap_a(stack, PRINT);
}
