/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:24:33 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/14 23:10:25 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_lis **lst)
{
	t_lis	*buffer;

	while (*lst)
	{
		buffer = (*lst)-> next;
		free(*lst);
		*lst = buffer;
	}
	(*lst) = NULL;
}	
