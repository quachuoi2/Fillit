/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/01 20:22:00 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_coordinate(ssize_t *x, ssize_t *y)
{
	*x = -1;
	*y = 0;
}

int	solve(char ***map, ssize_t size, t_tetris *lst, int cr)
{
	t_coord	crd;

	crd.y = -1;
	while (++crd.y < size)
	{
		crd.x = -1;
		while (++crd.x < size)
		{
			if ((*map)[crd.y][crd.x] == '.' && crd.x + lst[cr].w_l[1] < size + 2
			&& crd.y + lst[cr].w_l[0] < size && try(map, size, crd, &lst[cr]))
			{
				if (put(map, crd, lst[cr], lst[cr].c) && (++cr == lst[0].ttl))
					return (1);
				reset_coordinate(&crd.x, & crd.y);
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

int	try(char ***map, ssize_t size, t_coord coord, t_tetris *tet)
{
	int		index;
	ssize_t	x;
	ssize_t	y;

	index = 1;
	while (index < 4)
	{
		x = coord.x + (*tet).box[index][1];
		y = coord.y + (*tet).box[index][0];
		if (x < 0 || y < 0 || x >= size || y >= size || (*map)[y][x] != '.')
			return (0);
		index++;
	}
	(*tet).coord.x = coord.x;
	(*tet).coord.y = coord.y;
	return (1);
}
