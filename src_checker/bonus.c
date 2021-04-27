/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 20:57:21 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 18:09:14 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	get_node(t_list *stack, size_t i)
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

void	print_stackbody(t_stack *stack, size_t pos, int init)
{
	while (pos)
	{
		if (pos > ft_lstsize(stack->a) && pos > ft_lstsize(stack->b))
			printf("%-28s\n", " ");
		else if (pos <= ft_lstsize(stack->a) && pos > ft_lstsize(stack->b))
			printf("%-4s%s%10d%s%-14s\n", " ", \
			BHWHT, get_node(stack->a, pos - 1), RESET, " ");
		else if (pos > ft_lstsize(stack->a) && pos <= ft_lstsize(stack->b))
			printf("%-18s%s%10d%s\n", " ", BHWHT, \
			get_node(stack->b, pos - 1), RESET);
		else
			printf("%-4s%s%10d%s%-4s%s%10d%s\n", " ", \
			BHWHT, get_node(stack->a, pos - 1), RESET, \
			" ", BHWHT, get_node(stack->b, pos - 1), RESET);
		pos--;
	}
	if (init)
		printf("\n%-4s%10s%-4s%10s\n", " ", "Stack A", " ", "Stack B");
}

void	print_stacks_bonus(t_stack *stack, t_cmd cmd, int count)
{
	size_t	pos;

	pos = ft_lstsize(stack->a) + ft_lstsize(stack->b);
	printf("------------------------------");
	printf("\nInstruction %d/%d\t%s\n", count + 1, cmd.count, cmd.list[count]);
	print_stackbody(stack, pos, 0);
	printf("\n%-4s%10s%-4s%10s\n", " ", "Stack A", " ", "Stack B");
}

void	print_stacks_color_bonus(t_stack *stack, t_cmd cmd, int count)
{
	size_t	pos;

	pos = ft_lstsize(stack->a) + ft_lstsize(stack->b);
	printf("------------------------------");
	printf("\nInstruction %d/%d\t%s\n", count + 1, cmd.count, cmd.list[count]);
	print_stackbody(stack, pos, 0);
	printf("\n%-4s%s%10s%s%-4s%10s%s\n", " ", BHRED, "Stack A", \
	BHBLU, " ", "Stack B", RESET);
}

void	hit_enter_bonus(void)
{
	char	c;

	c = 0;
	printf("Press any key to continue...\n");
	read(1, &c, 1);
}
