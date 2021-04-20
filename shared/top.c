/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   top.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/16 21:44:57 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/16 21:46:35 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_list	*top(t_list *stack)
{
	return (ft_lstlast(stack));
}
