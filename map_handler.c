/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:50:15 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/11 18:11:11 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	tet_mapping(char *t)
{
	t_tetris	tet;
	int			col;
	int			row;
	int			box_count;

	col = 0;
	row = 0;
	box_count = 0;
	while (t[col])
	{
		if (t[col] == '#')
		{
			tet.box[box_count][0] = row;
			tet.box[box_count][1] = col % 5;
			box_count++;
		}
		if (t[col] == '\n')
			row++;
		col++;
	}
	return (tet);
}

void	tet_place(char ***map, t_coord coord, t_tetris tet, char c)
{
	int	index;
	int	x;
	int	y;

	index = -1;
	while (++index < 4)
	{
		x = coord.x + tet.box[index][1] - tet.box[0][1];
		y = coord.y + tet.box[index][0] - tet.box[0][0];
		(*map)[y][x] = c;
	}
}

char	**map_gen(size_t size)
{
	char	**map;
	size_t	i;

	map = (char **)ft_memalloc(sizeof (char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * size + 1);
		ft_memset(map[i++], '.', size);
	}
	return (map);
}

void	map_liberator(char ***map, size_t size)
{
	while (size--)
		ft_strdel(*map + size);
	ft_memdel((void **)map);
}

size_t	map_print(char **map, size_t size)
{
	int	i;
	int	i2;

	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			ft_putchar(map[i][i2++]);
			//ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
	return (size);
}
