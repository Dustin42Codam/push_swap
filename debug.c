/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 21:04:51 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 21:58:24 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	print_all(t_list *list, char **cmds)
{
	int i = 0;
	if (list)
	{
		while (list)
		{
			printf("[%d] %d\n", i, list->content);
			i++;
			list = list->next;
		}
	}
	if (cmds)
	{
		i = 0;
		while (cmds[i])
		{
			printf("[%s]\n", cmds[i]);
			i++;
		}
	}
}
