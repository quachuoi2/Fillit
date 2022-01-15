# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oskari <oskari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/15 20:11:58 by oskari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c algo.c map_handler.c error.c
OBJS= $(SOURCES:.c=.o)
HEADER= libft/libft.h
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT)
	@gcc $(FLAGS) $(SOURCES) $(LIBFT) $(HEADER) -o $(NAME)

leak:
	@gcc $(FLAGS) $(SOURCES) $(LIBFT) $(HEADER) -fsanitize=leak

clean:
	@rm -f $(wildcard *.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
