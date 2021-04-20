/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 16:47:38 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/23 13:23:37 by dkrecisz      ########   odam.nl         */
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
	char *input = 0;

	free(input);

	if (!input)
		printf("no input\n");
	return (0);
}
