# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/11 16:01:35 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= *.c #dont forget to name all the files individually
HEADER= libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all:
	@gcc $(SOURCES) $(LIBFT) -I libft

leak:
	@gcc $(SOURCES) $(LIBFT) -I libft -fsanitize=leak

clean:
	@rm -f $(wildcard *.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
