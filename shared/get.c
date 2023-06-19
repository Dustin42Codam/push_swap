/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 02:50:18 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/15 02:57:51 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*get(t_list *stack, size_t index)
{
	t_list	*tmp;

	tmp = stack;
	if (index >= ft_lstsize(stack))
		return (0);
	while (index > 0)
	{
		tmp = tmp->next;
		index--;
	}
	return (tmp);
}
