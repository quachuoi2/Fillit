/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:38:49 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/10 18:01:31 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TETRIS_END 20
# define TETRIS_MAX 26
# include "libft.h"
# include <fcntl.h>
#include <stdio.h> //remooove

typedef struct s_tetris
{
	int		box[4][2];
	char	c;
}	t_tetris;

typedef struct s_ipt
{
	char	**array;
	int		count;
}	t_ipt;

t_tetris	tet_mapping(char *t, int index);
t_tetris	*swap(t_tetris *tet_list, int count);
char		**map_gen(size_t size);
void		map_liberator(char ***map, size_t size);
void		map_print(char **map, size_t size);
int			search(char **map, size_t size, t_tetris tet);
int			comp(char ***map, size_t size, t_tetris tet);
int			try_pos(char ***map, size_t size, int i, int i2, int x, t_tetris tet);
#endif
