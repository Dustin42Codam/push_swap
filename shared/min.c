/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/16 21:57:28 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/16 23:21:57 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*min(t_list *stack)
{
	t_list	*min;
	t_list	*tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
