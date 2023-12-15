/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:54:18 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/15 21:16:37 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msg_error(void)
{
	write(2, "Error\n", 7);
	exit (errno);
}

static char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str_jointed;

	str_jointed = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_jointed)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			((unsigned char *)str_jointed)[i] = ((unsigned char *)s1)[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			((unsigned char *)str_jointed)[i + j] = ((unsigned char *)s2)[j];
			j++;
		}
		((unsigned char *)str_jointed)[i + j] = '\0';
		free(s1);
		return (str_jointed);
	}
	else
		return (NULL);
}

static void	check_chars(char ***matriz)
{
	int	i;
	int	j;

	i = 0;
	while ((*matriz)[i])
	{
		if (ft_atoi((*matriz)[i]) > 2147483647 || \
		ft_atoi((*matriz)[i]) < -2147483648)
			msg_error();
		j = 0;
		while ((*matriz)[i][j])
		{
			if ((!(ft_isdigit((*matriz)[i][j])) && (*matriz)[i][0] != '-') \
			|| ((*matriz)[i][0] == '-' && (*matriz)[i][1] == '\0'))
			{
				ft_allfree(*matriz, ft_matrizlen(*matriz));
				msg_error();
			}
			j++;
		}
		i++;
	}
}

static char	**join_split_args(char **argv)
{
	char	*array;
	char	**matriz;
	int		i;

	array = calloc(sizeof(char), 1);
	i = 1;
	while (argv[i])
	{
		array = strjoin(array, argv[i]);
		array = strjoin(array, " ");
		i++;
	}
	matriz = ft_split(array, ' ');
	free(array);
	return (matriz);
}

void	split_check_args(int argc, char **argv, char ***matriz)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		*matriz = join_split_args(argv);
		check_chars(matriz);
		i = 0;
		while ((*matriz)[i])
		{
			j = i + 1;
			while ((*matriz)[j])
			{
				if (ft_atoi((*matriz)[i]) == ft_atoi((*matriz)[j]))
				{
					ft_allfree(*matriz, ft_matrizlen(*matriz));
					msg_error();
				}
				j++;
			}
			i++;
		}
	}
	else
		exit(0);
}
