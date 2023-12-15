/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_a2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:27:16 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/14 23:27:54 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	comb1(t_lis **stack)
{
	ra(stack, 0);
	sa(stack, 0);
	rra(stack, 0);
}

static void	comb2(t_lis **stack)
{
	ra(stack, 0);
	sa(stack, 0);
	rra(stack, 0);
	sa(stack, 0);
}

static void	comb3(t_lis **stack)
{
	sa(stack, 0);
	ra(stack, 0);
	sa(stack, 0);
	rra(stack, 0);
}

static void	comb4(t_lis **stack)
{
	sa(stack, 0);
	ra(stack, 0);
	sa(stack, 0);
	rra(stack, 0);
	sa(stack, 0);
}

void	comb(t_lis **stack, int comb)
{
	if (comb == 1)
		comb1(stack);
	else if (comb == 2)
		comb2(stack);
	else if (comb == 3)
		comb3(stack);
	else if (comb == 4)
		comb4(stack);
}
