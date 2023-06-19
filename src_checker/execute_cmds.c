/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmds.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 02:27:31 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 18:12:27 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "bonus.h"
#include "../shared/stack.h"
#include <unistd.h>

void	init_table(t_jump *jump)
{
	jump->table[0] = swap_a;
	jump->table[1] = swap_b;
	jump->table[2] = swap_a_b;
	jump->table[3] = push_a;
	jump->table[4] = push_b;
	jump->table[5] = rotate_a;
	jump->table[6] = rotate_b;
	jump->table[7] = rotate_a_b;
	jump->table[8] = reverse_rotate_a;
	jump->table[9] = reverse_rotate_b;
	jump->table[10] = reverse_rotate_a_b;
}

void	execute_cmds(t_stack *stack, t_cmd cmd, t_flags flags)
{
	t_jump	jump;
	int		i;

	i = 0;
	init_table(&jump);
	if (flags.bitfield)
		print_stackbody(stack, ft_lstsize(stack->a), 1);
	while (i < cmd.count)
	{
		jump.table[cmd.id[i]](stack, NO_PRINT);
		if (flags.bitfield > COLORS)
			print_stacks_bonus(stack, cmd, i);
		if (flags.bitfield & DELAY)
			sleep(1);
		else if (flags.bitfield & ENTER)
		{
			hit_enter_bonus();
			print_stacks_bonus(stack, cmd, i);
		}
		else if (flags.bitfield & COLORS)
			print_stacks_color_bonus(stack, cmd, i);
		i++;
	}
}
