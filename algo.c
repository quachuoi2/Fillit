/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/10 06:46:50 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	comp(char ***map, size_t size, t_tetris tet, char c)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			if (try_pos(map, size, i, i2++, 0, tet, c) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int	try_pos(char ***map, size_t size, int i, int i2, int x, t_tetris tet, char c)
{
	if (x == 4)
		return (1);
	if (i >= size || i2 >= size)
		return (0);
	if ((*map)[i][i2] == '.' && try_pos(map, size, i + (tet.box[x + 1][0] - tet.box[x][0]), i2 + (tet.box[x + 1][1] - tet.box[x][1]), x + 1, tet, c) == 1)
		(*map)[i][i2] = c;
	else
		return (0);
	return (1);
}
