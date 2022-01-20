/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:38:49 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/20 03:04:31 by qnguyen          ###   ########.fr       */
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
	ssize_t	x;
	ssize_t	y;
}				t_coord;

typedef struct s_tetris
{
	char	c;
	int		ttl;
	ssize_t	box[4][2];
	ssize_t	w_l[2];
	t_coord	coord;
}				t_tetris;

typedef struct s_input
{
	char	**array;
	int		count;
}	t_input;

/* main.c */
void		get_tet_size(t_tetris *tet);
int			read_input(t_input *ipt, char *file);
t_tetris	tet_mapping(char **t, int i, int total);
ssize_t		fillit(char ***map, t_tetris *tet_list);

/* error.c */
void		reset_coordinate(ssize_t *x, ssize_t *y);
int			print_error(void);
int			free_tetri(int max, int outcome, t_input *tetri);
int			error_check(t_input *tetri);

/* map_handler.c */
void		map_liberator(char ***map, ssize_t size);
char		**map_generator(ssize_t size);
int			put(char ***map, t_coord coord, t_tetris tet, char c);
ssize_t		map_printer(char **map, ssize_t size);

/* algo.c */
int			try(char ***map, ssize_t size, t_coord coord, t_tetris *tet);
int			solve(char ***map, ssize_t size, t_tetris *lst, int cr);
#endif