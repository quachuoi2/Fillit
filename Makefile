# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/01/16 16:27:10 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= fillit
SOURCES= main.c algo.c map_handler.c error.c
HEADER= libft/
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT) $(HEADER)
	@gcc $(SOURCES) $(LIBFT) -I $(HEADER) -o $(NAME)

leak:
	@gcc $(FLAGS) $(SOURCES) $(LIBFT) $(HEADER) -o $(NAME) -fsanitize=leak

clean:
	@rm -f $(wildcard *.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
