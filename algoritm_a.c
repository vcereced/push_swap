/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 21:58:14 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 19:41:34 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_combs(t_lis **stack)
{
	if (((*stack)-> index < (*stack)-> next-> index) && ((*stack)-> next-> \
index > (*stack)-> next-> next-> index) && ((*stack)-> index < (*stack)-> \
next-> next-> index))
		comb(stack, 1);
	else if (((*stack)-> index > (*stack)-> next-> index) && ((*stack)-> \
next-> index < (*stack)-> next-> next-> index) && ((*stack)-> index < \
	(*stack)-> next-> next-> index))
		sa(stack, 0);
	else if (((*stack)-> index < (*stack)-> next-> index) && ((*stack)-> \
next-> index > (*stack)-> next-> next-> index) && ((*stack)-> index > \
	(*stack)-> next-> next-> index))
		comb(stack, 2);
	else if (((*stack)-> index > (*stack)-> next-> index) && ((*stack)-> \
next-> index < (*stack)-> next-> next-> index) && ((*stack)-> index > \
	(*stack)-> next-> next-> index))
		comb(stack, 3);
	else if (((*stack)-> index > (*stack)-> next-> index) && ((*stack)-> \
next-> index > (*stack)-> next-> next-> index) && ((*stack)-> index > \
	(*stack)-> next-> next-> index))
		comb(stack, 4);
}

void	last3numbers_a(t_lis **stack, int gt_chunk)
{
	int	n;

	reverse(stack, gt_chunk);
	n = lst_size_chunk(*stack, gt_chunk);
	if (n == 3)
	{
		check_combs(stack);
	}
	else if (n == 2)
	{
		if ((*stack)-> index > (*stack)-> next-> index)
			sa(stack, 0);
	}
}

void	choose_operation_a(t_lis **stack_a, t_lis **stack_b, int steps, \
int *chunk)
{
	if (steps == 0)
	{
		(*stack_a)-> chunk = *chunk;
		pb(stack_a, stack_b, 0);
	}
	else if (steps == 1)
		ra(stack_a, 0);
	else if (steps > 1)
		ra(stack_a, 0);
	else if (steps < 0)
		rra(stack_a, 0);
}

int	shortest_way_a(t_lis *stack, int mid_num)
{
	t_lis	*last;
	int		forward;
	int		back;

	last = lstlast(stack);
	forward = 0;
	while (stack -> num >= mid_num && stack != NULL)
	{
		stack = stack ->next;
		forward++;
	}
	back = 1;
	while (last -> num >= mid_num && last)
	{
		last = last -> prev;
		back++;
	}
	if (forward <= back)
		return (forward);
	else
		return (-1);
}
