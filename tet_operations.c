/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:47:07 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/07 16:39:49 by okinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
	converts string index to y_coordinate
*/

int	ct_y(char *tet, int index)
{
	int	height;
	int	count;

	height = 0;
	count = 0;
	while (count <= index)
	{
		if (tet[count] == '\n')
			height++;
		count++;
	}
	return (height);
}

char	map_tet_pos(t_map *map, int x, int y, char *tet, int index)
{
	return (map->rect[y + ct_y(tet, index)][x + ct_x(tet, index)]);
}

/*
	converts string index to x_coordinate
*/
int	ct_x(char *tet, int index)
{
	int	width;
	int	count;

	count = 0;
	width = 0;
	while (count < index)
	{
		width++;
		if (tet[count] == '\n')
			width = 0;
		count++;
	}
	return (width);
}

/*
	TODO: this needs to scan x axis left and right AND y axis up and down..
	I'll probably make it compress them totally differently,
	this is kinda ghetto and obviously won't pass norm.
	Also doesn't work for some pieces :D
*/

void	compress_tetrimino(char **tet)
{
	char	*compressed;
	int		t;
	char	x_match;
	int		x;
	int		y;

	t = 0;
	x_match = '0';
	compressed = ft_strnew(12);
	while ((*tet)[t] != '\0' && ft_strchr((*tet) + t, '#') != NULL)
	{
		x = t % 5;
		y = t / 5;
		while ((*tet)[(y * 5) + x] == '.')
			x++;
		x_match = (*tet)[(y * 5) + x];
		x = t % 5;
		while ((*tet)[(y * 5) + x] == '.')
			y++;
		if (x_match == '#' && (*tet)[(y * 5) + x] == '#')
			ft_strncat(compressed, (*tet) + t, 1);
		t++;
		if (t / 5 > y && ft_strlen(compressed) > 0)
			ft_strcat(compressed, "\n");
	}
	free (*tet);
	*tet = compressed;
}

/*void	compress_tetrimino(char **tet)
{
	char	*compressed;
	char	matches[4][4];
	int		t;

	t = 0;
	while ((*tet)[t] != '\0' && ft_strchr((*tet) + t, '#') != NULL)
	{
		if (tet[t] == '#')
			matches[t % 5][t / 5] = (*tet)[t];
		t++;
	}
	t = 0;
	while (t < 16) 
	{
		
		t++;
	}
}*/
