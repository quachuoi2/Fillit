/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/15 20:26:11 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetris	tet_mapping(char *t, int i, int total)
{
	t_tetris	tet;
	int			col;
	int			row;
	int			box_count;

	row = 0;
	col = 0;
	box_count = 0;
	tet.c = i + 'A';
	tet.ttl = total;
	while (t[col])
	{
		if (t[col] == '#')
		{
			tet.box[box_count][0] = row;
			tet.box[box_count][1] = col % 5;
			box_count++;
		}
		if (t[col] == '\n')
			row++;
		col++;
	}
	return (tet);
}

t_input	read_input_file(char *file)
{
	t_input	ipt;
	int		ret;
	int		p_ret;
	int		fd;

	fd = open(file, O_RDONLY);
	ipt.count = 0;
	ipt.array = (char **)malloc(sizeof(char *) * TETRIS_MAX + 1);
	while (ipt.count < 27)
	{
		ipt.array[ipt.count] = (char *)malloc(sizeof(char) * TETRIS_END + 2);
		ret = read(fd, ipt.array[ipt.count], TETRIS_END + 1);
		if (ret == 0)
		{
			ft_strdel(ipt.array + ipt.count);
			if (p_ret != 20)
				ipt.count = -100;
			return (ipt);
		}
		ipt.array[ipt.count][TETRIS_END] = '\0';
		ipt.count++;
		p_ret = ret;
	}
	return (ipt);
}

int	error_check(char *tetri, int tetri_count)
{
	int	i;
	int	block_counter;

	block_counter = 0;
	i = 0;
	while (tetri[i] != '\0' && i <= 20)
	{
		if ((tetri[i] != '\n' && tetri[i] != '#' && tetri[i] != '.')
			|| (tetri[0] == '\n') || (tetri[i] == '\n' && tetri[i + 1] == '\n')
			|| (tetri[i] == '#' && tetri[i + 1] != '#' && tetri[i + 5] != '#'
				&& tetri[i - 1] != '#' && tetri[i - 5] != '#'))
			return (-1);
		block_counter += (tetri[i] == '#');
		i++;
	}
	if (i < 20 || block_counter != 4 || tetri_count > 26)
		return (-1);
	return (1);
}

int	fillit(char ***map, t_tetris *tet_list)
{
	int			i;

	i = ft_sqrt(4 * tet_list[0].ttl);
	if (i * i < (4 * tet_list[0].ttl))
		i++;
	*map = map_generator(i);
	while (solve(map, i, tet_list, 0) != 1)
	{
		map_liberator(map, i);
		i++;
		*map = map_generator(i);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char		**map;
	static int	i;
	t_tetris	*tet_list;
	t_input		tetri;

	if (argc <= 1)
		ft_putendl("usage: missing argument");
	else
	{
		tetri = read_input_file(argv[1]);
		if (tetri.count < 0)
			return (print_error());
		tet_list = (t_tetris *)ft_memalloc(sizeof(t_tetris) * tetri.count);
		while (i < tetri.count)
		{
			if (error_check(tetri.array[i], tetri.count) == -1)
				return (print_error());
			tet_list[i] = tet_mapping(tetri.array[i], i, tetri.count);
			free(tetri.array[i++]);
		}
		free(tetri.array);
		map_liberator(&map, map_printer(map, fillit(&map, tet_list)));
		free(tet_list);
	}
	return (0);
}
