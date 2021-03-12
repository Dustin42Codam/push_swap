/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/12 19:00:12 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "checker.h"
#include "libft/include/libft.h"

static void	free_nodes(t_list *node)
{
	t_list *tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	node = NULL;
}

static void	clean_up(t_stack *stack, char **commands)
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
}

static void	exit_error(t_stack *stack)
{
	free_nodes(stack->a);
	free_nodes(stack->b);
	free(stack);

	ft_putstr_fd("Error\n", 2);

	exit(1);
}

static int	check_dup(t_list *list, int nb)
{
	while (list && list->next)
	{
		if (list->content == nb)
			return (1);
		list = list->next;
	}
	return (0);
}

static int	read_arguments(int argc, char *argv[], t_stack *stack)
{
	t_list	*node;
	long	nb;
	int		i;

	while (argc > 1)
	{
		i = 0;
		argc--;
		if ((argv[argc][i] == '-' || argv[argc][i] == '+') \
			 && ft_isdigit(argv[argc][i + 1]))
			i++;
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i]) == 0)
				return (1);
			i++;
		}
		nb = ft_atol(argv[argc]);
		node = ft_lstnew((int)nb);
		if (node)
			ft_lstadd_back(&stack->a, node);
		if (!node || nb > INT_MAX || nb < INT_MIN || check_dup(stack->a, nb))
			return (1);
	}
	return (0);
}

static void	print_stack(t_list *list)
{
	int i = 0;
	while (list)
	{
		printf("[%d] %d\n", i, list->content);
		i++;
		list = list->next;
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
			exit_error(stack);
		commands = read_commands();
		if (!commands)
			exit_error(stack);
		clean_up(stack, commands);
	}
	return (0);
}
