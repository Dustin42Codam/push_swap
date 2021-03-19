/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/19 03:58:28 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "bonus.h"
#include <stdlib.h>
#include <stdio.h>

static int	get_node(t_list *stack, int i)
{
	t_list	*tmp;

	tmp = stack;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp->content);
}

static void	print_stacks(t_stack *stack)
{
	t_print	print;
	int		len_a;
	int		len_b;
	int		pos;

	len_a = ft_lstsize(stack->a);
	len_b = ft_lstsize(stack->b);
	pos = len_a + len_b;

	printf("len_a: %d\nlen_b: %d\n", len_a, len_b);
	while (pos)
	{
		if (pos > len_a && pos > len_b)
			printf("%-28s\n", " ");
		else if (pos <= len_a && pos > len_b)
			printf("%-4s%10d%-14s\n", " ", get_node(stack->a, pos - 1), " ");
		else if (pos > len_a && pos <= len_b)
			printf("%-18s%10d\n", " ", get_node(stack->b, pos - 1));
		else
			printf("%-4s%10d%-4s%10d\n", " ", get_node(stack->a, pos - 1), \
										" ", get_node(stack->b, pos - 1));
		pos--;
	}
	printf("%-4s%10s%-4s%10s\n", " ", "Stack A", " ", "Stack B");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_list	*node;
	int		i;

	if (argc > 1 && argv[1][0] == 'd')
	{
		printf("[%-4s%10d%-4s%10d]\n", " ", 21, " ", -123553);
		printf("[%-4s%10d%-4s%10d]\n", " ", 0, " ", 0);
		printf("[%-4s%10s%-4s%10s]\n", " ", "Stack A", " ", "Stack B");
		return (0);
	}
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	// stack->a = (t_list *)ft_calloc(1, sizeof(t_list));
	// stack->b = (t_list *)ft_calloc(1, sizeof(t_list));
	for (i = 0; i < 10; i += 3)
	{
		node = (t_list *)ft_calloc(1, sizeof(t_list));
		node->content = i;
		ft_lstadd_back(&stack->a, node);
	}

	for (i = 140; i < 150; i += 2)
	{
		node = (t_list *)ft_calloc(1, sizeof(t_list));
		node->content = i;
		ft_lstadd_back(&stack->b, node);
	}


	print_stacks(stack);


	while (stack->a)
	{
		node = stack->a->next;
		free(stack->a);
		stack->a = node;
	}
	stack->a = 0;

	while (stack->b)
	{
		node = stack->b->next;
		free(stack->b);
		stack->b = node;
	}
	stack->b = 0;

	free(stack);

	return (0);
}
