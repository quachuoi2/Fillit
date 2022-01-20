/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:50:15 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/20 03:10:29 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	put(char ***map, t_coord coord, t_tetris tet, char c)
{
	int		index;
	ssize_t	x;
	ssize_t	y;

	index = 0;
	while (index < 4)
	{
		x = coord.x + tet.box[index][1] - tet.box[0][1];
		y = coord.y + tet.box[index][0] - tet.box[0][0];
		(*map)[y][x] = c;
		index++;
	}
	return (1);
}

char	**map_generator(ssize_t size)
{
	char	**map;
	ssize_t	i;

	map = (char **)ft_memalloc(sizeof (char *) * (long unsigned)size);
	i = 0;
	while (i < size)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * (long unsigned)size + 1);
		ft_memset(map[i], '.', (size_t)size);
		i++;
	}
	return (map);
}

void	map_liberator(char ***map, ssize_t size)
{
	while (size--)
		ft_strdel(*map + size);
	ft_memdel((void **)map);
}

ssize_t	map_printer(char **map, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
	return (size);
}
