/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/14 18:32:00 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(char ***map, size_t size, t_tetris *lst, int cr)
{
	t_coord	crd;

	crd.y = -1;
	while (++crd.y < size)
	{
		crd.x = -1;
		while (++crd.x < size)
		{
			if ((*map)[crd.y][crd.x] == '.' && try(map, size, crd, &lst[cr]))
			{
				if (put(map, crd, lst[cr], lst[cr].c) && (++cr == lst[0].ttl))
					return (1);
				crd.x = -1;
				crd.y = 0;
			}
			else if (crd.x == size - 1 && crd.y == size - 1)
			{
				if (cr-- == 0)
					return (0);
				put(map, lst[cr].coord, lst[cr], '.');
				crd = lst[cr].coord;
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
