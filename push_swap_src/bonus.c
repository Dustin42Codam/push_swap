/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 20:57:21 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/22 00:23:07 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"
#include <stdio.h>

static t_list	*get_node(t_list *stack, int i)
{
	t_list	*tmp;

	tmp = stack;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}

void	print_stacks_ps(t_stack *stack)
{
	int		len_a;
	int		len_b;
	int		pos;
	t_list	*node_a;
	t_list	*node_b;

	len_a = ft_lstsize(stack->a);
	len_b = ft_lstsize(stack->b);
	pos = len_a + len_b;
	printf("\n------------------------------\n");
	// printf("\nInstruction #%d %s\n\n", count, cmd.list[count]);
	while (pos)
	{
		// node_a = get_node(stack->a, pos - 1);
		// node_b = get_node(stack->b, pos - 1);
		if (pos > len_a && pos > len_b)
			printf("%-28s\n", " ");
		else if (pos <= len_a && pos > len_b)
			printf("%-4s%10d[%ld]{%ld}%-14s\n", " ", get_node(stack->a, pos - 1)->content, get_node(stack->a, pos - 1)->group, \
													get_node(stack->a, pos - 1)->sort_id, " ");
		else if (pos > len_a && pos <= len_b)
			printf("%-18s%10d[%ld]{%ld}\n", " ", get_node(stack->b, pos - 1)->content, get_node(stack->b, pos - 1)->group, \
											get_node(stack->b, pos - 1)->sort_id);
		else
			printf("%-4s%10d[%ld]{%ld}%-4s%10d[%ld]{%ld}\n", " ", get_node(stack->a, pos - 1)->content, get_node(stack->a, pos - 1)->group, \
										get_node(stack->a, pos - 1)->sort_id, " ", get_node(stack->b, pos - 1)->content, \
										get_node(stack->b, pos - 1)->group, get_node(stack->b, pos - 1)->sort_id);
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
