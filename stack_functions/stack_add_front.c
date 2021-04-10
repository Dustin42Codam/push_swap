/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_add_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 21:47:59 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/31 14:47:55 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_front(t_stack **bottom, t_stack *new)
{
	if (bottom == NULL || new == NULL)
		return ;
	new->next = *bottom;
	new->prev = 0;
	new->marked = 0;
	*bottom = new;
}
