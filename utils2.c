/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:19:08 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/14 23:09:16 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middle_point_number(t_lis *stack, int i, int gt_chunk)
{
	i = i / 2;
	while (stack)
	{
		if (stack -> index == i && stack -> chunk == gt_chunk)
			return (stack -> num);
		stack = stack->next;
	}
	return (stack -> num);
}

int	get_greater_chunk(t_lis *stack)
{
	int	gt;

	gt = 0;
	while (stack)
	{
		if (stack -> chunk > gt)
			gt = stack -> chunk;
		stack = stack -> next;
	}
	return (gt);
}

int	check_availables_gt_chunk(t_lis *stack, int gt_chunk)
{
	int	gt;

	gt = 0;
	while (stack)
	{
		if (stack -> chunk == gt_chunk)
			gt++;
		stack = stack -> next;
	}
	return (gt);
}

static int	index_node(t_lis *stack, t_lis *ptr, int gt_chunk)
{
	int	i;

	i = 0;
	while (ptr)
	{
		if (ptr->num < stack ->num && ptr->chunk == gt_chunk)
			i++;
		ptr = ptr -> next;
	}
	stack -> index = i;
	return (i);
}

int	indexing_nodes(t_lis *stack_a, int gt_chunk)
{
	t_lis	*ptr;
	int		i;
	int		length;

	length = 0;
	ptr = stack_a;
	while (stack_a)
	{
		if (stack_a->chunk == gt_chunk)
		{
			i = index_node(stack_a, ptr, gt_chunk);
			if (length < i)
				length = i;
		}
		stack_a = stack_a -> next;
	}
	return (++length);
}
