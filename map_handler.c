/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:50:15 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/16 17:51:57 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	put(char ***map, t_coord coord, t_tetris tet, char c)
{
	int	index;
	int	x;
	int	y;

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

char	**map_generator(size_t size)
{
	char	**map;
	size_t	i;

	map = (char **)ft_memalloc(sizeof (char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * size + 1);
		ft_memset(map[i], '.', size);
		i++;
	}
	return (map);
}

void	map_liberator(char ***map, size_t size)
{
	while (size--)
		ft_strdel(*map + size);
	ft_memdel((void **)map);
}

size_t	map_printer(char **map, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
	return (size);
}
