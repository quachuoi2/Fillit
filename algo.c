/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/13 03:17:02 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	comp(char ***map, size_t size, t_tetris *list, int c_box)
{
	t_coord	coord;

	coord.y = -1;
	while (++coord.y < size)
	{
		coord.x = -1;
		while (++coord.x < size)
		{
			if (try_pos(map, size, coord, &list[c_box]) == 1)
			{
				tet_place(map, coord, list[c_box], list[c_box].c);
				if (++c_box == list[0].total)
					return (1);
				coord.y = 0;
				coord.x = -1;
			}
			else if (coord.x == size - 1 && coord.y == size - 1)
			{
				if (c_box-- == 0)
					return (0);
				tet_place(map, list[c_box].coord, list[c_box], '.');
				coord = list[c_box].coord;
			}
		}
	}
}

int	try_pos(char ***map, size_t size, t_coord coord, t_tetris *tet)
{
	int	index;
	int	x;
	int	y;

	index = 1;
	while (index < 4)
	{
		x = coord.x + (*tet).box[index][1] - (*tet).box[0][1];
		y = coord.y + (*tet).box[index][0] - (*tet).box[0][0];
		if (x >= size || y >= size || (*map)[y][x] != '.'
			|| (*map)[coord.y][coord.x] != '.')
			break ;
		index++;
	}
	if (index == 4)
	{
		(*tet).coord.x = coord.x;
		(*tet).coord.y = coord.y;
		return (1);
	}
	return (0);
}
