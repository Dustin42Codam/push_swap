/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chonk.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/23 03:56:02 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/24 19:27:31 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus.h"

void	merge_groups(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->group = 0;
		tmp = tmp->next;
	}
}

void	check_swap_a(t_stack *stack)
{
	if (check_sort_grp_a(stack->a, top(stack->a)->group))
		swap_a(stack, PRINT);
}

void	check_swap_b(t_stack *stack)
{
	if (check_sort_grp_b(stack->b, top(stack->b)->group))
		swap_b(stack, PRINT);
}

void	chonk_a(t_stack *stack)
{
	size_t	group = top(stack->a)->group;
	size_t	median;


	if (group_size(stack->a, group) == 2)
		check_swap_a(stack);								//return???
	if (group_size(stack->b, top(stack->b)->group) == 2)
		check_swap_b(stack);								//return???
	/**
	 * If stack A is sorted then merge all groups
	 * by setting all group IDs of the stack to 0.
	 * Return to calling function chonk_b().
	**/
/* 	if (top(stack->a)->group == 2 && top(stack->b)->group == 3
		&& group_size(stack->b, 3) == 1)
	{
		// printf("median:\t%ld\n", median);
		print_stacks_ps(stack);
		exit(42);
	} */
	if (check_sort_a(stack) == 0)
		return (merge_groups(stack->a));
	while (!check_sort_grp_a(stack->a, top(stack->a)->group) && \
		!check_sort_grp_b(stack->b, top(stack->b)->group))
		push_group_to_a(stack, top(stack->b)->group);

	// Push lower chonk to stack b
	// if group id is bigger than 0 it means that sub stack is unsorted
	if (top(stack->a)->group > 0)
	{
		median = get_median(stack, stack->a, top(stack->a)->group);
		group = top(stack->a)->group;
		size_t	next_group = top(stack->b)->group + 1;
		while (find_value_a(stack->a, median, group))
		{
			if (top(stack->a)->group == group && \
				top(stack->a)->sort_id < median)
			{
				// if (top(stack->a)->group + 1 == top(stack->b)->group)
					// top(stack->a)->group++; 
				// top(stack->a)->group = next_group;
				top(stack->a)->group++;		// necessary???
				push_b(stack, PRINT);
			}
			else
			{
				rotate_a(stack, PRINT);
				stack->regroup++;
			}
		}
		while (stack->regroup)
		{
			reverse_rotate_a(stack, PRINT);
			stack->regroup--;
		}
/* 		if (top(stack->a)->group == 2 && top(stack->b)->group == 3
			&& group_size(stack->b, 3) == 1)
		{
			// printf("median:\t%ld\n", median);
			print_stacks_ps(stack);
			exit(42);
		} */
		chonk_a(stack);
	}
	chonk_b(stack);
}

void	chonk_b(t_stack *stack)
{
	size_t	group = top(stack->b)->group;
	size_t	median;
	if (group_size(stack->b, group) == 2)
		check_swap_b(stack);								//return???
	if (group_size(stack->a, top(stack->a)->group) == 2)
		check_swap_a(stack);
/* 	if (top(stack->a)->group == 0 && ft_lstsize(stack->b) == 3)
	{
		// printf("median:\t%ld\n", median);
		push_group_to_a(stack, top(stack->b)->group);
		push_group_to_a(stack, top(stack->b)->group);
		print_stacks_ps(stack);
		exit(42);
	} */
	while (top(stack->b) && \
		!check_sort_grp_a(stack->a, top(stack->a)->group) && \
		!check_sort_grp_b(stack->b, top(stack->b)->group))
		push_group_to_a(stack, top(stack->b)->group);

	
	if (check_sort_a(stack) == 0 && ft_lstsize(stack->b) == 0)
	{
		// printf("DONE!\n");
		exit(0);
	}

/* 	if (top(stack->a)->group == 0 && top(stack->b)->group == 1 &&
		group_size(stack->b, 1) == 5)
	{
		print_stacks_ps(stack);
		exit(21);
	} */

	// Push upper chonk to stack a
	// if (top(stack->b)->group > 1)
	if (top(stack->b)->group > 0)	// Change condition!!!
	{
		median = get_median(stack, stack->b, top(stack->b)->group);
		group = top(stack->b)->group;
		while (find_value_b(stack->b, median, top(stack->b)->group))
		{
			if (top(stack->b)->group == group && \
				top(stack->b)->sort_id >= median)
			{
				top(stack->b)->group++;
				push_a(stack, PRINT);
			}
			else
			{
				rotate_b(stack, PRINT);
				stack->regroup++;
			}
		}
		while (stack->regroup)
		{
			reverse_rotate_b(stack, PRINT);
			stack->regroup--;
		}
/* 		if (top(stack->a)->group == 2 && top(stack->b)->group == 1 &&
			group_size(stack->b, 1) == 2)
		{
			print_stacks_ps(stack);
			exit(21);
		} */
		chonk_a(stack);
	}
	chonk_b(stack);
}
