/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 01:47:43 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 19:43:31 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_lis **stack_a, t_lis **stack_b, int flag)
{
	flag = 0;
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}

void	rb(t_lis **stack, int flag)
{
	ra(stack, 1);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	ra(t_lis **stack, int flag)
{
	t_lis	*last;
	t_lis	*head;

	last = lstlast(*stack);
	head = (*stack)->next;
	head->prev = NULL;
	(*stack)->next = NULL;
	(*stack)-> prev = last;
	last -> next = *stack;
	*stack = head;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rrb(t_lis **stack, int flag)
{
	rra(stack, 1);
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rra(t_lis **stack, int flag)
{
	t_lis	*last;
	t_lis	*llast;

	last = lstlast(*stack);
	llast = last->prev;
	last ->next = *stack;
	last -> prev = NULL;
	(*stack)-> prev = last;
	llast ->next = NULL;
	*stack = last;
	if (flag == 0)
		write(1, "rra\n", 4);
}
