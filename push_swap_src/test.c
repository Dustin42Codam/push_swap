/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 19:59:19 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/22 19:08:48 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../shared/stack.h"
#include "../push_swap_src/push_swap.h"



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
	t_stack			*stack;
	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));

	// t_list	*stack = ft_lstnew(-420);
	t_list	*node1 = ft_lstnew(1);
	t_list	*node2 = ft_lstnew(2);
	t_list	*node3 = ft_lstnew(3);
	t_list	*node4 = ft_lstnew(4);
	t_list	*node5 = ft_lstnew(5);

	ft_lstadd_back(&stack->a, node5);
	ft_lstadd_back(&stack->a, node4);
	ft_lstadd_back(&stack->a, node3);
	ft_lstadd_back(&stack->a, node2);
	ft_lstadd_back(&stack->a, node1);

	while (pre_sort_stack(stack->a, id))
		id++;

	init_stack_data(stack);

	stack->a->group = 1;
	stack->a->next->group = 1;
	stack->a->next->next->group = 1;


	// push_b(stack, NO_PRINT);
	// push_b(stack, NO_PRINT);
// 
	// swap_b(stack, NO_PRINT);
	// swap_a(stack, NO_PRINT);

	// printf("%ld\n", stack->b->sort_id);
	// printf("%ld\n", stack->b->next->sort_id);

	// printf("%d\n", compare_top_sort_id_a(stack));
	printf("%d\n", compare_top_sort_id_b(stack));

}
