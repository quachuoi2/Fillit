/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:38:49 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/07 16:18:44 by okinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

typedef struct s_map
{
	char	**rect;
	int		size;
}	t_map;

typedef struct s_tet
{
	char	*tet;
	char	width;
	char	height;
}	t_tet;

void	compress_tetrimino(char **tet);
char	map_tet_pos(t_map *map, int x, int y, char *tet, int index);
int		ct_x(char *tet, int index);
int		ct_y(char *tet, int index);

/* DEBUG */
void	printboard_debug(t_map *map, int x, int y);
void	printboard(t_map *map);

#endif
