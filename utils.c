/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:20:29 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 00:44:29 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsizenormal(t_lis *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	lst_size_chunk(t_lis *lst, int gt_chunk)
{
	int	i;

	i = 0;
	while (lst != NULL && lst->chunk == gt_chunk)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

void	gen_nodes(t_lis **stack_a, t_lis **stack_b, char	**argv)
{
	t_lis	*head;
	int		n;

	*stack_a = NULL;
	*stack_b = NULL;
	n = 0;
	while (argv[n])
	{
		if (n == 0)
			head = lstadd_back(NULL, lstnew(ft_atoi(argv[n])));
		else
			lstadd_back(head, lstnew(ft_atoi(argv[n])));
		n++;
	}
	*stack_a = head;
}
