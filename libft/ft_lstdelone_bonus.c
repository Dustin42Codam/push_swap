/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 12:26:15 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/08 21:22:45 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}
