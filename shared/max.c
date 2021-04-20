/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/16 21:57:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/16 21:59:56 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*max(t_list *stack)
{
	t_list	*max;
	t_list	*tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (max->content < tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
