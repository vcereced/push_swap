/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:49:27 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 00:06:39 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

long	ft_atoi(const char *str)
{
	long	i;
	long	minus;
	long	aux;

	i = 0;
	minus = 1;
	aux = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		aux = (str[i] - '0') + (aux * 10);
		i++;
	}
	aux *= minus;
	return (aux);
}
/*
int main (void)
{
	const char str [] = "  11223e4";
	printf("miia : %i\n", ft_atoi(str));
	printf("real : %i", atoi(str));
	return (0);
}*/