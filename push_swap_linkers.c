/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:45:57 by vcereced          #+#    #+#             */
/*   Updated: 2023/06/15 17:59:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lis	**stack)
{
	t_lis	*tmp;

	tmp = (*stack)->next;
	if (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = *stack;
		tmp = (*stack)->next;
	}	
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}

t_lis	*lstlast(t_lis *lst)
{
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	lst_add_front(t_lis **lst, t_lis **new)
{
	t_lis	*ptr;

	ptr = (*new)-> next;
	if (!(*lst))
	{
		*lst = *new;
		(*lst)-> next = NULL;
		(*lst)-> prev = NULL;
		*new = ptr;
		if (*new)
			(*new)->prev = NULL;
	}
	else
	{
		(*new)-> next = *lst;
		(*lst)-> prev = *new;
		*lst = *new;
		*new = ptr;
	}
}

t_lis	*lstadd_back(t_lis *lst, t_lis *new)
{
	t_lis	*last;

	last = lstlast(lst);
	if (last)
		lst_add_front(&new, &last);
	else
		lst = new;
	return (lst);
}

t_lis	*lstnew(int n)
{
	t_lis	*node;

	node = (t_lis *)malloc(sizeof(t_lis));
	if (!node)
		return (NULL);
	node->num = n;
	node->index = 0;
	node ->chunk = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
