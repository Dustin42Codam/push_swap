/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/17 15:49:13 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/15 00:49:25 by dkrecisz      ########   odam.nl         */
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

static void	enumerate_stack(t_stack *stack)
{
	unsigned int	i;
	t_list			*node;

	i = 0;
	node = stack->a;
	while (node)
	{
		node->index = i;
		node->check = 0;
		node = node->next;
		i++;
	}
}

static void	set_values(t_list **node, unsigned int id, unsigned char check)
{
	(*node)->sort_id = id;
	(*node)->check = check;
}

static int	pre_sort_stack(t_list *stack, unsigned int id)
{
	t_list	*tmp;
	t_list	*min;

	tmp = stack;
	while (tmp->check != 0)
	{
		tmp = tmp->next;
		if (!tmp)
			return (0);
	}
	min = tmp;
	id++;
	set_values(&min, id, 1);
	while (tmp->next)
	{
		if (min->content > tmp->next->content && tmp->next->check == 0)
		{
			set_values(&min, 0, 0);
			min = tmp->next;
			set_values(&tmp->next, id, 1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack			*stack;
	unsigned int	id;

	if (argc > 1)
	{
		id = 0;
		stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (read_argv(argc, argv, stack))
			clean_up(stack, ERROR);
		enumerate_stack(stack);
		while (pre_sort_stack(stack->a, id))
			id++;
		// print_stack(stack);
		// print_stack(stack);
		// sort(stack);
		// print_stack(stack);
		selection_sort(stack);
		clean_up(stack, NO_ERROR);
	}
	return (0);
}
