# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/07 16:21:33 by okinnune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c get_next_line.c tet_operations.c debug.c
HEADER= libft.h
LIBFT= libft/libft.a
FLAGS= #-Wall -Wextra #-Werror

all:
	gcc $(SOURCES) $(LIBFT) -I libft -I. $(FLAGS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
