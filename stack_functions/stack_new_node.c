/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_new_node.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 20:54:52 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/29 19:17:30 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new_node(int content)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (new == 0)
		return (0);
	new->content = content;
	new->marked = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}
