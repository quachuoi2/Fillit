# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/10 01:34:29 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= *.c
HEADER= libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all:
	@gcc $(SOURCES) $(LIBFT) -I libft
	#dont forget $(FLAGS)

leak:
	@gcc $(SOURCES) $(LIBFT) -I libft -fsanitize=leak
clean:
	@rm -f $(wildcard *.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
