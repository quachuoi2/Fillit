/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:38:49 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/11 18:34:36 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TETRIS_END 20
# define TETRIS_MAX 26
# include "libft.h"
# include <fcntl.h>
#include <stdio.h> //remooove

typedef struct s_coordinate
{
	size_t x;
	size_t y;
}				t_coord;

typedef struct	s_tetris
{
	char	c;
	int		box[4][2];
	int		total;
	t_coord	coord;
}				t_tetris;

typedef struct s_ipt
{
	char	**array;
	int		count;
}	t_ipt;


t_tetris	tet_mapping(char *t);
char		**map_gen(size_t size);
void		map_liberator(char ***map, size_t size);
size_t		map_print(char **map, size_t size);
int	search(char **map, size_t size, t_tetris tet);
int	comp(char ***map, size_t size, t_tetris *tet_list, int c_box);
int	try_pos(char ***map, size_t size, int i, int i2, int x, t_tetris *tet_list, int c_box);

int	comp1(char ***map, size_t size, t_coord coord, t_tetris *tet_list, int c_box);
int	try_pos1(char ***map, size_t size, t_coord coord, t_tetris *tet);
void	tet_place(char ***map, t_coord coord, t_tetris tet, char c);
#endif
