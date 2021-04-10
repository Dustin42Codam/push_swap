/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 18:00:59 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/02 18:16:34 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	print_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->a;
	while (tmp)
	{
		printf("%d.	%d	{%d}	[%d]\n", tmp->index, tmp->content,
											tmp->sort_id, tmp->check);
		tmp = tmp->next;
	}
}
