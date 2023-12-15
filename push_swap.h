/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:46:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/05 21:01:03 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <errno.h>

typedef struct list
{
	int			num;
	int			index;
	int			chunk;
	struct list	*next;
	struct list	*prev;
}t_lis;

/*HANDLE ERRORS*/
int		msg_error(void);
void	lstclear(t_lis **lst);
char	**ft_allfree(char **array, unsigned int i);
void	split_check_args(int argc, char **argv, char ***matriz);
int		check_sorted(t_lis *stack);

/*FUNCTIONS*/
void	gen_nodes(t_lis **stack_a, t_lis **stack_b, char	**argv);
void	print_stacks(t_lis	*stack_a, t_lis *stack_b);
int		lstsizenormal(t_lis *lst);
int		get_greater_chunk(t_lis *stack);
int		middle_point_number(t_lis *stack, int i, int gt_chunk);
int		check_availables_gt_chunk(t_lis *stack, int gt_chunk);
int		indexing_nodes(t_lis *stack_a, int gt_chunk);
t_lis	*lstlast(t_lis *lst);
int		lst_size_chunk(t_lis *lst, int gt_chunk);

/*MOMVEMENT*/
void	pb(t_lis **stack_a, t_lis **stack_b, int flag);
void	pa(t_lis **stack_a, t_lis **stack_b, int flag);
void	sa(t_lis **stack_a, int flag);
void	sb(t_lis **stack_b, int flag);
void	rra(t_lis **stack_a, int flag);
void	rrb(t_lis **stack, int flag);
void	ra(t_lis **stack, int flag);
void	rb(t_lis **stack, int flag);
void	rr(t_lis **stack_a, t_lis **stack_b, int flag);
void	rrr(t_lis **stack_a, t_lis **stack_b, int flag);
void	ss(t_lis **stack_a, t_lis **stack_b, int flag);

/*LINKERS*/
void	swap(t_lis	**stack);
t_lis	*lstnew(int n);
t_lis	*lstadd_back(t_lis *lst, t_lis *new);
void	lst_add_front(t_lis **lst, t_lis **new);

/*ALGORITM A*/
int		check_availables_lowers(t_lis *stack, int mid_num);
void	last3numbers_a(t_lis **stack, int gt_chunk);
int		shortest_way_a(t_lis *stack, int mid_num);
void	comb(t_lis **stack, int comb);
void	choose_operation_a(t_lis **stack_a, t_lis **stack_b, \
int steps, int *chunk);
void	reverse(t_lis **stack, int gt_chunk);

/*ALGORITM B*/
int		check_availables_greaters(t_lis *stack, int mid_num);
void	last3numbers_b(t_lis **stack_a, t_lis **stack_b, \
int gt_chunk, int *chunk);
int		shortest_way_b(t_lis *stack, int mid_num);
void	choose_operation_b(t_lis **stack_a, t_lis **stack_b, \
int steps, int *chunk);

#endif