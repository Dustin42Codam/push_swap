/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 21:28:09 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/20 10:43:43 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

# include "libft.h"
# include "stack.h"

// debug stuff delete later
#include <stdio.h>
#include <stdlib.h>

// debug stuff delete later
void	print_stack(t_stack *stack);

int		read_argv(int ac, char *av[], t_stack *stack);
void	sort(t_stack *stack);
int		selection_sort(t_stack *stack);
void	push_min(t_stack *stack, t_list *min);
t_list	*find_min(t_list *stack);


/**
 * Sorting algorithms
**/
void	median_method(t_stack *stack, size_t median);
size_t	get_median(t_stack *stack_data, t_list *stack, size_t group);


/**
 * Stack functions
**/
void	init_stack_data(t_stack *stack);
void	refresh_stack_data(t_stack *stack);
int		compare_top(t_list *stack);
void	enumerate_stack(t_list *stack);


#endif
