/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 20:57:21 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/03/18 08:12:04 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void print_stack_a(t_list *element)
{
	if (element->next)
		print_stack_a(element->next);
	printf("%d\n", element->content);
}

void	print_stack_bonus(t_stack *stack)
{
	printf("++++++++++ STACK A ++++++++++\n");
	print_stack_a(stack->a);
	printf("++++++++++++ END +++++++++++++\n");
}

void	print_all(t_stack *stack, char **cmds)
{
	t_list	*tmp;
	int		i = 0;
	printf("++++++++++ STACK A ++++++++++\n");
	if (ft_lstsize(stack->a))
	{
		tmp = stack->a;
		while (tmp)
		{
			printf("[%d] %d\n", i, tmp->content);
			i++;
			tmp = tmp->next;
		}
	}
	printf("++++++++++ STACK B ++++++++++\n");
	if (ft_lstsize(stack->b))
	{
		tmp = stack->b;
		while (tmp)
		{
			printf("[%d] %d\n", i, tmp->content);
			i++;
			tmp = tmp->next;
		}
	}
	printf("++++++++++++ END +++++++++++++\n");
	return ;
	i = 0;
	while (cmds[i])
	{
		printf("[%s]\n", cmds[i]);
		i++;
	}
}
