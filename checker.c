/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 22:53:15 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "libft/include/libft.h"

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

/* static void	clean_up(t_stack *stack, char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
	free_nodes(stack->a);
	free_nodes(stack->b);
	free(stack);
} */

static void	clean_up(t_stack *stack, char **commands, int error)
{
	int	i;

	i = 0;
	if (commands)
	{
		while (commands[i])
		{
			free(commands[i]);
			i++;
		}
		free(commands);
	}
	free_nodes(stack->a);
	free_nodes(stack->b);
	free(stack);
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	**commands;

	if (argc > 1)
	{
		stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (read_arguments(argc, argv, stack))
			clean_up(stack, 0, ERROR);
		commands = read_commands();
		if (!commands)
			clean_up(stack, 0, ERROR);
		if (validate_commands(commands))
			clean_up(stack, commands, ERROR);
		clean_up(stack, commands, NO_ERROR);
	}
	return (0);
}
