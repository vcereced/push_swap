/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 01:40:46 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 19:42:50 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_lis **stack_a, int flag)
{
	swap(stack_a);
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_lis **stack_b, int flag)
{
	sa(stack_b, 1);
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	pa(t_lis **stack_a, t_lis **stack_b, int flag)
{
	pb(stack_b, stack_a, 1);
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_lis **stack_a, t_lis **stack_b, int flag)
{
	lst_add_front(stack_b, stack_a);
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (flag == 0)
		write(1, "pb\n", 3);
}
