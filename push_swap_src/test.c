/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 19:59:19 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/10 22:10:22 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft/include/libft.h"

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d.	%d	{%d.}	[%d]\n", tmp->index, tmp->content, \
										tmp->sort_id, tmp->check);
		tmp = tmp->next;
	}
}

static void	enumerate_stack(t_list *stack)
{
	unsigned int	i;
	t_list			*node;

	i = 0;
	node = stack;
	while (node)
	{
		node->index = i;
		node->check = 0;
		node = node->next;
		i++;
	}
}

static unsigned int	get_sort_id(t_list *stack)
{
	t_list			*tmp;
	unsigned int	id;

	tmp = stack;
	id = 0;
	while (tmp)
	{
		if (tmp->check == 1)
			id++;
		tmp = tmp->next;
	}
	return (id);
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

void	main(void)
{
	unsigned int	id = 0;
	t_list	*stack = ft_lstnew(-420);
	t_list	*node1 = ft_lstnew(21);
	t_list	*node2 = ft_lstnew(-7000);
	t_list	*node3 = ft_lstnew(3);
	t_list	*node4 = ft_lstnew(-133300);
	t_list	*node5 = ft_lstnew(-419);

	ft_lstadd_back(&stack, node1);
	ft_lstadd_back(&stack, node2);
	ft_lstadd_back(&stack, node3);
	ft_lstadd_back(&stack, node5);

	enumerate_stack(stack);

	while (pre_sort_stack(stack, id) == 1)
		id++;
	// while (pre_sort_stack(stack));
	
	print_stack(stack);
}
