/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/14 15:38:45 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void reset_coord(t_coord *crd)
{
	crd->x = -1;
	crd->y = 0;
}

int	solve(char ***map, size_t size, t_tetris *lst, int cur)
{
	t_coord	crd;

	crd.y = -1;
	while (++crd.y < size)
	{
		crd.x = -1;
		while (++crd.x < size)
		{
			if ((*map)[crd.y][crd.x] == '.' && try(map, size, crd, &lst[cur]))
			{
				tet_place(map, crd, lst[cur], lst[cur].c);
				if (++cur == lst[0].total)
					return (1);
				reset_coord(&crd);
			}
			else if (crd.x == size - 1 && crd.y == size - 1)
			{
				if (cur-- == 0)
					return (0);
				tet_place(map, lst[cur].coord, lst[cur], '.');
				crd = lst[cur].coord;
			}
		}
	}
	return (0);
}

int	try(char ***map, size_t size, t_coord coord, t_tetris *tet)
{
	int				index;
	unsigned int	x;
	unsigned int	y;

	index = 1;
	while (index < 4)
	{
		x = coord.x + (*tet).box[index][1] - (*tet).box[0][1];
		y = coord.y + (*tet).box[index][0] - (*tet).box[0][0];
		if (x >= size || y >= size || (*map)[y][x] != '.')
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
