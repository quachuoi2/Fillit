# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oskari <oskari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/13 04:37:35 by oskari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c algo.c map_handler.c
OBJS= $(SOURCES:.c=.o)
HEADER= libft/libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all:
	@gcc $(SOURCES) $(LIBFT) $(HEADER) -I libft -o $(NAME)

leak:
	@gcc $(SOURCES) $(LIBFT) -I libft -fsanitize=leak

clean:
	@rm -f $(wildcard *.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
