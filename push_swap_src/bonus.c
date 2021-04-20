/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 20:57:21 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/24 21:15:52 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "bonus.h"
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

void	print_stacks_bonus(t_stack *stack, t_cmd cmd, int count)
{
	int		len_a;
	int		len_b;
	int		pos;

	len_a = ft_lstsize(stack->a);
	len_b = ft_lstsize(stack->b);
	pos = len_a + len_b;
	printf("------------------------------");
	printf("\nInstruction #%d %s\n\n", count, cmd.list[count]);
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

void	press_enter_bonus(void)
{
	char enter;

	enter = 0;
	printf("\nPress enter to continue...\n");
	while (enter != '\r' && enter != '\n')
	{
		enter = getchar();
	}
}
