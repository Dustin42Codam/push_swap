/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_help_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkrecisz <dkrecisz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 19:31:33 by dkrecisz      #+#    #+#                 */
/*   Updated: 2021/04/27 15:25:29 by dkrecisz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

static void	print_examples(void)
{
	char	*cmd;

	cmd = "ARG=\"3 2 5 4 1\"; ./push_swap $ARG | ./checker $ARG";
	printf("%s\n\nEXAMPLE\n%s $> %s\n", BHWHT, RESET, cmd);
	printf("%s\n\nOUTPUT\n%s", BHWHT, RESET);
	printf("\t%sOK%s%5sIf push_swap gave correct instructions to sort.\n", \
			BWHT, RESET, " ");
	printf("\t%sKO%s%5sIf push_swap gave incorrect instrucions.\n", \
			BWHT, RESET, " ");
	printf("\t%sError%s%2sIf one of the below errors occured:\n", \
			BWHT, RESET, " ");
	printf("\t%6s- Some arguments are not integers.\n", " ");
	printf("\t%6s- Some arguments are bigger than an integer.\n", " ");
	printf("\t%6s- There are duplicates.\n", " ");
	printf("\t%6s- An instruction don't exist.\n", " ");
	printf("\t%6s- An instruction is incorrectly formatted.\n", " ");
	printf("\t%6s- Memory allocation failed.\n", " ");
}

static void	print_notes(void)
{
	char	*ruby;
	char	*shuf;
	char	*cmd2;
	char	*pyviz_repo;
	char	*my_repo;

	ruby = "ARG=`ruby -e \"puts (-200..200).to_a.shuffle.join(' ')\"`;";
	shuf = "ARG=$(shuf -i 0-400 -n 400 | tr '\\n' ' ');";
	cmd2 = "./push_swap $ARG | ./checker $ARG";
	pyviz_repo = "git clone https://github.com/o-reo/push_swap_visualizer";
	my_repo = "git clone https://github.com/Dustin42Codam/push_swap.git";
	printf("%s\n\nNOTES%s\n", BHWHT, RESET);
	printf("%s\nHere are some useful commands for the eval:%s\n", \
			BHWHT, RESET);
	printf("%s\n1. Run push_swap with random values [ruby]:%s\n$> %s%s\n", \
			BHWHT, RESET, ruby, cmd2);
	printf("%s\n\n2. Run with random values AND count instructions [ruby]:\
			%s\n$> %s%s && ./push_swap $ARG | wc -l\n", \
			BHWHT, RESET, ruby, cmd2);
	printf("%s\n\n3. Run push_swap with random values [shuf]:%s\n$> %s%s\n", \
			BHWHT, RESET, shuf, cmd2);
	printf("%s\n\n4. push_swap visualizer [requires python3]:%s\n$> %s\n", \
			BHWHT, RESET, pyviz_repo);
	printf("%s\n\n5. My repo for reference:%s\n$> %s\n\n", \
			BHWHT, RESET, my_repo);
}

void	print_help_bonus(void)
{
	printf("%s\n\nChecker - Checks if your push_swap messed up to sort!%s", \
			BHWHT, RESET);
	printf("%s\n\nUSAGE: ./checker [options] \"list of integers\"%s\n\n", \
			BHWHT, RESET);
	printf("%sOPTIONS%s\n", BWHT, RESET);
	printf("\t%s-v%s:%15sDisplay stacks after each instruction.\n", \
			BWHT, RESET, " ");
	printf("\t%s-c%s:%15sSame as '-v' %sbut %swith %snice %scolors%s.\n", \
			BWHT, RESET, " ", BHRED, BHYEL, BHGRN, BHBLU, RESET);
	printf("\t%s-s%s:%15sDisplay stacks in a slow mode.\n", \
			BWHT, RESET, " ");
	printf("\t%s-h%s:%15sPrints help for this %svery%s complex program.\n", \
			BWHT, RESET, " ", BWHT, RESET);
	print_examples();
	print_notes();
}
