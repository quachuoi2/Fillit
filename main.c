/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/07 16:44:17 by okinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdio.h> //remooove
#include <fcntl.h>

int check_fit (char *tet, t_map map, int x, int y);
int	map_solve(t_map map, char **tetr, int x, int y);


/*
	TODO: add protection for malloc here.
*/

t_map *init_map (int size)
{
	int y = 0;
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	map->rect = malloc(sizeof(char *) * size);
	while (y < size) 
	{
		map->rect[y] = ft_strnew(size);
		ft_memset(map->rect[y], 46, size);
		y++;
	}
	map->size = size;
	return (map);
}

/*
	Recursively tries to fit tetris pieces in the map,
	should recurse back to previous solution if failed to find with
	current board (doesn't do that yet)
*/

int	map_solve(t_map map, char **tetr, int x, int y)
{
	//printf("CALLED MAP SOLVE WITH X:%iY:%i\n", x, y);
	if (**tetr == '\0')
		return (1);
	if (check_fit(*tetr, map, x, y) == 1)
	{
		tetr++;
		return (map_solve(map, tetr, 0, 0));
		/*
			^
			Current tetris piece fit to the map, so let's try the next one,
			starting with coordinates 0,0
		*/
	}
	else
	{
		/*	Didn't fit, so let's move on to the next coordinate */
		x++;
		if (x >= map.size)
		{
			x = 0;
			y++;
		}
		//printf("Y %i\n", y);
		if (y >= map.size)
			return (0);
		return (map_solve(map, tetr, x, y));
	}
}

/*
	Draws tetrimino 'tet' in map coordinates 'x' and 'y' using 'draw'
	character
*/

static void draw_tet_in_map (char *tet, t_map *map, int x, int y, char draw)
{
	int t;

	t = 0;
	while (ft_strchr(tet + t, '#') != NULL)
	{
		if (tet[t] == '#' && map_tet_pos(map, x, y, tet, t) == '.')
			map->rect[y+ct_y(tet, t)][x+ct_x(tet, t)] = draw;
		t++;
	}
}

/*
	Returns 1 if tetrimino 'tet' can fit onto map coordinates x and y.

	TODO: this 'overchecks' collisions, so for example a piece that is 2 wide will only fit
	in a space that is 3 wide, it's some kind of indexing problem and easily fixed. Might
	be something off with ct_x, or just logic inside this function
*/

int check_fit (char *tet, t_map map, int x, int y)
{
	int t = 0;
	//printf("CHECKFIT CALL WITH X:%iY:%i\n", x, y);
	while (ft_strchr(tet + t, '#') != NULL
		&& (x + ct_x(tet, t) < map.size && y + ct_y(tet, t) < map.size)) //Testing if current piece is out of bounds
	{
		//printf("TRYING TO FIT TO COORDINATES X:%i Y:%i\nMAP SIZE = %i", x + ct_x(tet, t), y + ct_y(tet, t), map.size);
		//printboard_debug(&map, x + ct_x(tet, t), y + ct_y(tet, t));
		if (!(map_tet_pos(&map, x, y, tet, t) == '.' || tet [t] != '#')) //Flip ! this to be more readable
			break;
		t++;
	}
	if (ft_strchr(tet + t, '#') == NULL)
	{
		draw_tet_in_map(tet, &map, x, y, 'x');
		printboard(&map);
		return (1);
		/*
			Found a valid placement for tetrimino,
			Draw it on the board and return (1)
		*/
	}
	return (0);
}

char **read_input_file(int fd)
{
	int		ret;
	char	**array;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * 26);
	while (i < 26)
	{
		array[i] = (char *)malloc(sizeof(char) * 22);
		ret = read(fd, array[i], 21);
		if (ret == 0)
		{
			/*
				NULL terminate the array with an empty string,
				used to know when we're out of tetris pieces
			*/
			array[i][0] = '\0';
			//free(array[i]);
			break;
		}
		array[i++][ret - 1] = '\0';
	}
	return (array);
}

int		main (int argc, char **argv)
{
	int		fd;
	char	**arr;
	t_map	*map;

	if (argc <= 1)
		ft_putendl("No arguments given!");
	else
	{
		fd = open(argv[1], O_RDONLY);
		arr = read_input_file(fd);
	}
	int i;
	i = 0;
	while (arr[i][0] != '\0')
	{
		printf("__________\ntetris %d:\n%s\n",i , arr[i]);
		compress_tetrimino(&(arr[i]));
		printf("compressed tetris %d:\n%s\n",i , arr[i]);
		i++;
	}
	map = init_map(5);
	map_solve(*map, arr, 0, 0);
	return (0);
}