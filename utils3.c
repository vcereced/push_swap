/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:44:01 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 19:43:57 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_lis	*stack_a, t_lis *stack_b)
{
	write(1, "\n---STACK A---\n", 15);
	while (stack_a)
	{
		ft_printf("%d  index(%d), chunk(%d)\n", stack_a->num, stack_a ->index, \
		stack_a ->chunk);
		stack_a = stack_a->next;
	}
	write(1, "\n---STACK B---\n", 15);
	while (stack_b)
	{
		ft_printf("%d  index(%d), chunk(%d)\n", stack_b->num, stack_b -> index, \
		stack_b -> chunk);
		stack_b = stack_b->next;
	}
	write(1, "-----------------------------------------------\n", 49);
}

int	check_sorted(t_lis *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
