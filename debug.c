/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:13:32 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/07 16:40:06 by okinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printboard(t_map *map)
{
	int iy;

	iy = 0;
	ft_putendl("MAP:\n");
	while (iy < map->size)
	{
		ft_putendl(map->rect[iy]);
		iy++;
	}
}

void	printboard_debug(t_map *map, int x, int y)
{
	int iy;
	int ix;

	iy = 0;
	ix = 0;
	ft_putendl("MAP DEBUG:\n");
	while (iy < map->size)
	{	
		while (ix < map->size)
		{
			if (ix == x && iy == y)
				ft_putchar('D');
			else
				ft_putchar(map->rect[iy][ix]);
			ix++;
		}
		iy++;
		ft_putchar('\n');
		ix = 0;
	}
}