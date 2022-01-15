/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:38:49 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/15 20:15:22 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TETRIS_END 20
# define TETRIS_MAX 26
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_coordinate
{
	size_t	x;
	size_t	y;
}				t_coord;

typedef struct s_tetris
{
	char	c;
	int		box[4][2];
	int		ttl;
	t_coord	coord;
}				t_tetris;

typedef struct s_input
{
	char	**array;
	int		count;
}	t_input;

int			print_error();

t_tetris	tet_mapping(char *t, int i, int total);

char		**map_generator(size_t size);

void		map_liberator(char ***map, size_t size);

size_t		map_printer(char **map, size_t size);

int			search(char **map, size_t size, t_tetris tet);

int			try(char ***map, size_t size, t_coord coord, t_tetris *tet);

int			put(char ***map, t_coord coord, t_tetris tet, char c);

int			solve(char ***map, size_t size, t_tetris *list, int c_box);
#endif
