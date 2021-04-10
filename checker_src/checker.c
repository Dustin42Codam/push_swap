/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/31 14:05:05 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

static void	free_nodes(t_list *node)
{
	t_list	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = NULL;
}

static void	clean_up(t_stack *stack, char **cmds, int error)
{
	int	i;

	i = 0;
	if (cmds)
	{
		while (cmds[i])
		{
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
	if (stack)
	{
		free_nodes(stack->a);
		free_nodes(stack->b);
		free(stack);
	}
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

static void	init_cmd(t_cmd *cmd)
{
	cmd->id = 0;
	cmd->count = 0;
}

int	main(int argc, char *argv[])
{
	t_cmd		cmd;
	t_flags		flags;
	t_stack		*stack;

	if (argc > 1)
	{
		stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (read_argv(argc, argv, stack, &flags))
			clean_up(stack, 0, ERROR);
		printf("%d\n", stack->a->content);
		exit(42);
		init_cmd(&cmd);
		cmd.list = read_cmds();
		if (!cmd.list)
			clean_up(stack, 0, ERROR);
		cmd.count = count_cmds(cmd.list);	//delete ? replace ft with vars
		cmd.id = (int *)ft_calloc(cmd.count + 1, sizeof(int));
		if (!cmd.id)
			clean_up(stack, cmd.list, ERROR);
		if (validate_cmds(&cmd))
		{
			free(cmd.id);
			clean_up(stack, cmd.list, ERROR);
		}
		execute_cmds(stack, cmd, flags);
		evaluate_stack(stack);
		free(cmd.id);
		clean_up(stack, cmd.list, NO_ERROR);
	}
	return (0);
}
