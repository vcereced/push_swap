/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_b2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:53:34 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/14 23:33:44 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_availables_greaters(t_lis *stack, int mid_num)
{
	while (stack)
	{
		if (stack -> num > mid_num)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

int	check_availables_lowers(t_lis *stack, int mid_num)
{
	while (stack)
	{
		if (stack -> num < mid_num)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

void	choose_operation_b(t_lis **stack_a, t_lis **stack_b, int steps, \
int *chunk)
{
	if (steps == 0)
	{
		(*stack_b)->chunk = *chunk;
		pa(stack_a, stack_b, 0);
	}
	else if (steps == 1)
		rb(stack_b, 0);
	else if (steps > 1)
		rb(stack_b, 0);
	else if (steps < 0)
		rrb(stack_b, 0);
}
