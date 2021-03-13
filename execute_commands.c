/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 02:27:31 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/13 04:32:18 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	execute_commands(t_stack *stack, char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		if (commands[i])
		printf("%s\n", commands[i]);
		i++;
	}
}
