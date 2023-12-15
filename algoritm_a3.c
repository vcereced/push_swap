/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_a3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:35 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/27 23:58:30 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	comb3(t_lis **stack)
{
	rra(stack, 0);
	sa(stack, 0);
}

static void	comb2(t_lis **stack)
{
	sa(stack, 0);
	rra(stack, 0);
}

static void	comb1(t_lis **stack)
{
	sa(stack, 0);
	rra(stack, 0);
	sa(stack, 0);
}

/**
 * @brief 
 * 
 * @param stack 
 * @param gt_chunk 
 */
static void	combs(t_lis **stack, int gt_chunk)
{
	if ((*stack)->chunk == gt_chunk && (*stack)->next->chunk == gt_chunk && \
	(*stack)->next->next->chunk == gt_chunk && (*stack)->index > (*stack)->\
	next->index && (*stack)->next->index < (*stack)->next->next->index && \
	(*stack)->index > (*stack)->next->next->index)
		comb1(stack);
	else if ((*stack)->chunk == gt_chunk && (*stack)->next->chunk == gt_chunk \
	&& (*stack)->next->next->chunk == gt_chunk && (*stack)->index > (*stack)->\
	next->index && (*stack)->next->index > (*stack)->next->next->index && \
	(*stack)->index > (*stack)->next->next->index)
		comb2(stack);
	else if ((*stack)->chunk == gt_chunk && (*stack)->next->chunk == gt_chunk \
	&& (*stack)->next->next->chunk == gt_chunk && (*stack)->index > (*stack)->\
	next->index && (*stack)->next->index < (*stack)->next->next -> index && \
	(*stack)->index < (*stack)->next->next->index)
		sa(stack, 0);
	else if ((*stack)->chunk == gt_chunk && (*stack)->next->chunk == gt_chunk \
	&& (*stack)->next->next->chunk == gt_chunk && (*stack)->index < (*stack)->\
	next->index && (*stack)->next->index > (*stack)->next->next -> index && \
	(*stack)->index > (*stack)->next->next -> index)
		rra(stack, 0);
	else if ((*stack)->chunk == gt_chunk && (*stack)->next->chunk == gt_chunk \
	&& (*stack)->next->next->chunk == gt_chunk && (*stack)->index < (*stack)->\
	next->index && (*stack)->next->index > (*stack)->next->next -> index && \
	(*stack)->index < (*stack)->next->next->index)
		comb3(stack);
}

void	reverse(t_lis **stack, int gt_chunk)
{
	int	n;

	n = lstsizenormal(*stack);
	while (lstlast(*stack)->chunk == gt_chunk && !check_sorted(*stack) && \
	n == 3)
		combs(stack, gt_chunk);
	if (n == 2)
	{
		if ((*stack)-> next-> chunk == gt_chunk && (*stack)->next->index < \
		(*stack)-> index)
			sa(stack, 0);
	}
	if (n > 3)
	{
		while (lstlast(*stack)-> chunk == gt_chunk)
		{
			rra(stack, 0);
			if ((*stack)->next->chunk == gt_chunk && (*stack)->next->index \
			< (*stack)->index)
				sa(stack, 0);
		}
	}
}
