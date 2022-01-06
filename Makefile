# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/06 19:28:25 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c get_next_line.c
HEADER= libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all:
	gcc $(SOURCES) $(LIBFT) -I libft $(FLAGS)

clean:
	rm -f $(wildcard *.o)

fclean: clean
	rm -f $(NAME)

re: fclean all
