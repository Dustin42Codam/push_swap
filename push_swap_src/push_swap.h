/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 21:28:09 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/25 04:59:25 by dkrecisz      ########   odam.nl         */
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

/**
 *	Read input + setup
**/
int		read_argv(int ac, char *av[], t_stack *stack);
void	init_stack_data(t_stack *stack, size_t stack_len);
void	enumerate_stack(t_list *stack);

/**
 * Sorting algorithms
**/
void	sort(t_stack *stack);
void	sort_easy(t_stack *stack);
void	sort_medium(t_stack *stack);
void	sort_hardcore(t_stack *stack);

/**
 * Sort utils
**/
size_t	get_median(t_list *stack, size_t group);

size_t	group_size(t_list *lst, size_t group);

int		compare_top(t_list *stack);

int		check_sort(t_list *stack);
int		check_sort_a(t_stack *stack);
int		check_sort_grp_a(t_list *stack, size_t group);
int		check_sort_grp_b(t_list *stack, size_t group);
void	check_complete_sort(t_stack *stack);

void	check_swap(t_stack *stack);
void	check_swap_b(t_stack *stack);
void	check_swap_a(t_stack *stack);

int		find_value_a(t_list *stack, size_t value, size_t group);
int		find_value_b(t_list *stack, size_t value, size_t group);

void	halve_group_a(t_stack *stack);
void	halve_group_b(t_stack *stack);

void	push_group_to_a(t_stack *stack, size_t group);

void	merge_groups(t_list *stack);

/**
 *	Exit + clean up functions
**/
void	clean_up(t_stack *stack, int error);
void	free_nodes(t_list *node);

#endif
