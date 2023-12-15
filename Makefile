# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 13:25:03 by vcereced          #+#    #+#              #
#    Updated: 2023/04/22 22:03:40 by vcereced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c handle_errors.c movements.c movements2.c \
push_swap_linkers.c utils.c utils2.c utils3.c algoritm_a.c algoritm_a2.c algoritm_a3.c algoritm_b.c algoritm_b2.c memory_leaks.c movements3.c

CFLAGS = -Wall -Werror -Wextra

OBJT = $(SRC:.c=.o)

CC = gcc

LIBFT = ./libft/libft.a

$(NAME): $(LIBFT) $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

all : $(NAME)

clean:
	rm -f $(OBJT)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

run: all
	./$(NAME) 23 4637 4854 37 1190 2188 425 3930 1086 2836 2043 2132 556 4864 1298 3861 503 518 144 4429 1641 2308 3708 1732 758 2425 1055 4180 4666 4555 4314 2289 4464 3542 4227 3314 700 2197 2778 4916 1140 4619 2241 1852 299 3552 3509 1417 4272 3619 432 1465 2347 4503 3592 2451 2598 1550 1911 4611 725 1002 2251 559 20 3659 613 489 4766 2107 1969 2040 529 416 1564 3779 219 3991 1598 1054 4131 4817 100 2714 3398 2584 1075 3446 2826 1748 4218 3786 1596 4628 1340 1870 908 4562 2764 2745

debug: all
	gcc -g $(OBJT) $(LIBFT)
	lldb ./a.out 23 4637 4854 37 1190 2188 425 3930 1086 2836 2043 2132 556 4864 1298 3861 503 518 144 4429 1641 2308 3708 1732 758 2425 1055 4180 4666 4555 4314 2289 4464

.PHONY: all clean fclean re
