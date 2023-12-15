/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:26:39 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 21:15:50 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
	for check leaks in main;
	atexit(check_leaks);
	check_leaks(void){
		system("leaks a.out")};
*/
void	check_leaks(void)
{
	system("leaks push_swap");
}

void	algoritm_b(t_lis **stack_a, t_lis **stack_b, int *chunk)
{
	int	i;
	int	mid_num;
	int	steps;
	int	gt_chunk;

	gt_chunk = get_greater_chunk(*stack_b);
	(*chunk)++;
	if (check_availables_gt_chunk(*stack_b, gt_chunk) > 3)
	{
		i = indexing_nodes(*stack_b, gt_chunk);
		mid_num = middle_point_number(*stack_b, i, gt_chunk);
		while (check_availables_greaters(*stack_b, mid_num))
		{
			steps = shortest_way_b(*stack_b, mid_num);
			choose_operation_b(stack_a, stack_b, steps, chunk);
		}
	}
	else
		last3numbers_b(stack_a, stack_b, gt_chunk, chunk);
}

void	algoritm_a(t_lis **stack_a, t_lis **stack_b, int *chunk)
{
	int	i;
	int	mid_num;
	int	steps;
	int	gt_chunk;

	gt_chunk = get_greater_chunk(*stack_a);
	while (check_availables_gt_chunk(*stack_a, gt_chunk) > 3)
	{
		i = indexing_nodes(*stack_a, gt_chunk);
		mid_num = middle_point_number(*stack_a, i, gt_chunk);
		(*chunk)++;
		while (check_availables_lowers(*stack_a, mid_num))
		{
			steps = shortest_way_a(*stack_a, mid_num);
			choose_operation_a(stack_a, stack_b, steps, chunk);
		}
	}
	i = indexing_nodes(*stack_a, gt_chunk);
	last3numbers_a(stack_a, gt_chunk);
}

static void	algoritm(t_lis **stack_a, t_lis **stack_b, int *chunk)
{
	algoritm_a(stack_a, stack_b, chunk);
	while (*stack_b)
	{
		algoritm_b(stack_a, stack_b, chunk);
		algoritm_a(stack_a, stack_b, chunk);
	}
	algoritm_a(stack_a, stack_b, chunk);
}

int	main(int argc, char	**argv)
{		
	t_lis	*stack_a;
	t_lis	*stack_b;
	char	**matriz;
	int		chunk;

	chunk = 0;
	split_check_args(argc, argv, &matriz);
	gen_nodes(&stack_a, &stack_b, matriz);
	if (!check_sorted(stack_a))
		algoritm(&stack_a, &stack_b, &chunk);
	ft_allfree(matriz, ft_matrizlen(matriz));
	lstclear(&stack_a);
	return (0);
}
