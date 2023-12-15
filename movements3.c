/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:25:29 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 19:43:42 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_lis **stack_a, t_lis **stack_b, int flag)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (flag == 0)
		write(1, "rrr\n", 5);
}

void	ss(t_lis **stack_a, t_lis **stack_b, int flag)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}
