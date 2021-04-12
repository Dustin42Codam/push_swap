/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 21:28:09 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/12 20:37:22 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ERROR 1
# define NO_ERROR 0

# include "include/libft.h"
# include "stack.h"

// debug stuff delete later
#include <stdio.h>
#include <stdlib.h>

// debug stuff delete later
void	print_stack(t_stack *stack);

int	read_argv(int ac, char *av[], t_stack *stack);

t_stack			*stack_new_node(int content);
void			stack_add_front(t_stack **bottom, t_stack *new);
t_stack			*stack_last(t_stack *lst);

size_t			stack_len(t_stack *stack);

void			stack_add_back(t_stack **alst, t_stack *new);
void			stack_delone(t_stack *lst, void (*del)(int));
void			stack_clear(t_stack **lst);

#endif
