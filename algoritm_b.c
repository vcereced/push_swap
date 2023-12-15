/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:10:57 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/14 23:09:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shortest_way_b(t_lis *stack, int mid_num)
{
	t_lis	*last;
	int		forward;
	int		back;

	last = lstlast(stack);
	forward = 0;
	while (stack -> num <= mid_num && stack != NULL)
	{
		stack = stack ->next;
		forward++;
	}
	back = 1;
	while (last->num <= mid_num && last)
	{
		last = last -> prev;
		back++;
	}
	if (forward <= back)
		return (forward);
	else
		return (-1);
}

static int	count_forward(t_lis *stack_b, int gt_chunk, int i)
{
	int	steps;
	int	forward;

	forward = 0;
	steps = 0;
	while (stack_b)
	{
		if (stack_b-> index == i && stack_b-> chunk == gt_chunk)
			forward = steps;
		stack_b = stack_b-> next;
		steps++;
	}
	return (forward);
}

static int	count_back(t_lis *stack, int gt_chunk, int i)
{
	int	back;
	int	steps;

	stack = lstlast(stack);
	steps = 1;
	back = 0;
	while (stack)
	{
		if (stack-> index == i && stack-> chunk == gt_chunk)
			back = steps;
		stack = stack-> prev;
		steps++;
	}
	return (back);
}

static int	shortest_way_chunk_index(t_lis *stack_b, int gt_chunk, int i)
{
	int	forward;
	int	back;

	forward = count_forward(stack_b, gt_chunk, i);
	back = count_back(stack_b, gt_chunk, i);
	if (forward <= back)
		return (forward);
	else
		return (-1);
}

void	last3numbers_b(t_lis **stack_a, t_lis **stack_b, int gt_chunk, \
int *chunk)
{
	int	i;
	int	steps;

	i = indexing_nodes(*stack_b, gt_chunk);
	i--;
	while (i >= 0)
	{
		steps = shortest_way_chunk_index(*stack_b, gt_chunk, i);
		if (steps == 0)
		{
			(*stack_b)->chunk = *chunk;
			pa(stack_a, stack_b, 0);
			i--;
		}
		else if (steps == 1)
			rb(stack_b, 0);
		else if (steps > 1)
			rb(stack_b, 0);
		else if (steps < 0)
			rrb(stack_b, 0);
	}
}
