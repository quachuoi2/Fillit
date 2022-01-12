/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/12 18:32:09 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	tet_mapping(char *t, char c, int total)
{
	t_tetris	tet;
	int			col;
	int			row;
	int			box_count;

	row = 0;
	col = -1;
	box_count = -1;
	tet.c = c;
	tet.total = total;
	while (t[++col])
	{
		if (t[col] == '#')
		{
			tet.box[++box_count][0] = row;
			tet.box[box_count][1] = col % 5;
		}
		if (t[col] == '\n')
			row++;
	}
	return (tet);
}

t_ipt	read_input_file(char *file)
{
	t_ipt	ipt;
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	ipt.count = 0;
	ipt.array = (char **)malloc(sizeof(char *) * TETRIS_MAX);
	while (ipt.count < 26)
	{
		ipt.array[ipt.count] = (char *)malloc(sizeof(char) * TETRIS_END + 1);
		ret = read(fd, ipt.array[ipt.count], TETRIS_END + 1);
		if (ret == 0)
		{
			ft_strdel(ipt.array + ipt.count);
			return (ipt);
		}
		ipt.array[ipt.count++][TETRIS_END] = '\0';
	}
	return (ipt);
}

int	error_check(char *tetri)
{
	int	i;
	int	block_counter;

	block_counter = 0;
	i = 0;
	while (tetri[i] != '\0')
	{
		if ((tetri[i] != '\n' && tetri[i] != '#' && tetri[i] != '.')
			|| (tetri[0] == '\n') || (tetri[i] == '\n' && tetri[i + 1] == '\n')
			|| (tetri[i] == '#' && tetri[i + 1] != '#' && tetri[i + 5] != '#'
				&& tetri[i - 1] != '#' && tetri[i - 5] != '#'))
			return (-1);
		block_counter += (tetri[i] == '#');
		i++;
	}
	if (i < 20 || block_counter != 4)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (1);
}

int	fillit(char ***map, t_tetris *tet_list)
{
	int			i;

	i = 2;
	*map = map_gennerator(i);
	while (comp(map, i, tet_list, 0) != 1)
	{
		map_liberator(map, i++);
		*map = map_gennerator(i);
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char		**map;
	char		c;
	static int	i;
	t_tetris	*tet_list;
	t_ipt		tetri;

	if (argc <= 1)
		ft_putendl("usage: missing argument");
	else
	{
		tetri = read_input_file(argv[1]);
		tet_list = (t_tetris *)ft_memalloc(sizeof(t_tetris) * tetri.count);
		c = 'A';
		while (i < tetri.count)
		{
			if (error_check(tetri.array[i]) == -1)
				return (-1);
			tet_list[i] = tet_mapping(tetri.array[i], c++, tetri.count);
			ft_strdel(tetri.array + i++);
		}
		ft_memdel((void **)&tetri.array);
		map_liberator(&map, map_printer(map, fillit(&map, tet_list)));
		ft_memdel((void **)&tet_list);
	}
	return (0);
}
