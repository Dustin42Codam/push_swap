/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/17 15:49:13 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/24 21:47:45 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

static void	clean_up(t_stack *stack, int error)
{
	int	i;

	i = 0;
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

int	main(int argc, char *argv[])
{
	t_stack		*stack;

	if (argc > 1)
	{
		stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (read_argv(argc, argv, stack))
			clean_up(stack, ERROR);
		clean_up(stack, NO_ERROR);
	}
	return (0);
}
