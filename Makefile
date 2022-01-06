# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/06 11:13:50 by okinnune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c get_next_line.c
HEADER= libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all:
	gcc $(SOURCES) $(LIBFT) -I libft -I. $(FLAGS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
