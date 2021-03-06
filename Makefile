# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:57:56 by okinnune          #+#    #+#              #
#    Updated: 2022/03/01 23:14:02 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
SOURCES= main.c algo.c map_handler.c error.c
HEADER= libft/
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
all: $(NAME)

$(NAME): $(SOURCES) $(LIBFT) $(HEADER)
	@gcc $(FLAGS) $(SOURCES) $(LIBFT) -I $(HEADER) -o $(NAME)

$(LIBFT):
	make -C libft

leak: $(SOURCES) $(LIBFT) $(HEADER)
	@gcc $(FLAGS) $(NITPICK) $(SOURCES) $(LIBFT) -I $(HEADER) -o $(NAME) -fsanitize=leak

clean:
	make -C libft clean
	@rm -f $(wildcard *.o)

fclean: clean
	make -C libft fclean
	@rm -f $(NAME)

re: fclean all
