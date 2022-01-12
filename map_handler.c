/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:50:15 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/12 15:43:00 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tet_place(char ***map, t_coord coord, t_tetris tet, char c)
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
}

char	**map_gennerator(size_t size)
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

size_t	map_printer(char **map, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
	return (size);
}
