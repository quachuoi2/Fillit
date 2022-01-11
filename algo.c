/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:18:18 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/11 18:37:40 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <time.h> //rm
void delay(int number_of_seconds) //rm
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int	comp1(char ***map, size_t size, t_coord coord, t_tetris *list, int c_box)
{
	while (coord.y < size)
	{
		while (coord.x < size)
		{
			if (try_pos1(map, size, coord, &list[c_box]) == 1)
			{
				tet_place(map, coord, list[c_box], list[c_box].c);
				coord.y = 0;
				coord.x = -1;
				c_box++;
				if (c_box == list[0].total)
					return (1);
			}
			coord.x++;
		}
		coord.y++;
		coord.x = 0;
	}
	if (c_box-- > 0)
	{
		tet_place(map, list[c_box].coord, list[c_box], '.');
		coord.y = list[c_box].coord.y;
		if (list[c_box].coord.x == size)
		{
			coord.x = 0;
			coord.y++;
		}
		else
			coord.x = list[c_box].coord.x + 1;
		if (coord.y < size && comp1(map, size, coord, list, c_box) == 1)
			return (1);
	}
	return (0);
}

int	try_pos1(char ***map, size_t size, t_coord coord, t_tetris *tet)
{
	int	index;
	int	x;
	int	y;

	index = 1;
	if ((*map)[coord.y][coord.x] == '.')
	{
		while (index < 4)
		{
			x = coord.x + (*tet).box[index][1] - (*tet).box[0][1];
			y = coord.y + (*tet).box[index][0] - (*tet).box[0][0];
			if (x >= size || y >= size || (*map)[y][x] != '.')
				break ;
			else
				index++;
		}
		if (index == 4)
		{
			(*tet).coord.x = coord.x;
			(*tet).coord.y = coord.y;
			return (1);
		}
	}
	return (0);
}

/* int	comp(char ***map, size_t size, t_tetris *list, int c_box)
{
	size_t	i;
	size_t	i2;

	if (c_box == list[0].total)
		return (1);
	i = 0;
	while (i < size)
	{
		i2 = 0;
		while (i2 < size)
		{
			if (try_pos(map, size, i, i2, 0, list, c_box) == 1)
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

int	try_pos(char ***map, size_t size, int i, int i2, int x, t_tetris *list, int c_box)
{
	if (x == 4)
		return (1);
	if (i >= size || i2 >= size)
		return (0);
	if ((*map)[i][i2] == '.' && try_pos(map, size, i + (list[c_box].box[x + 1][0] - list[c_box].box[x][0]), i2 + (list[c_box].box[x + 1][1] - list[c_box].box[x][1]), x + 1, list, c_box) == 1)
			(*map)[i][i2] = list[c_box].c;
	else
		return (0);
	if (x == 0)
	{
		if (comp(map, size, list, c_box + 1) == 1)
			return (1);
		else
			return (0);
	}
	return (1);
} */
