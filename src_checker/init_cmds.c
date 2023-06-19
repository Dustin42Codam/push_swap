/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cmds.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/26 00:53:00 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 15:38:01 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

static int	count_cmds(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	init_cmd(t_cmd *cmd, t_stack *stack)
{
	cmd->id = 0;
	cmd->count = 0;
	cmd->list = read_cmds(stack);
	if (!cmd->list)
	{
		if (ft_lstsize(stack->a) == 1)
		{
			ft_putstr_fd("OK\n", 1);
			clean_up(stack, 0, NO_ERROR);
			exit(0);
		}
		else if (ft_lstsize(stack->a) > 1)
			evaluate_stack(stack);
		clean_up(stack, 0, NO_ERROR);
		exit(0);
	}
	cmd->count = count_cmds(cmd->list);
	cmd->id = (int *)ft_calloc(cmd->count + 1, sizeof(int));
	if (!cmd->id)
		clean_up(stack, cmd->list, ERROR);
}
