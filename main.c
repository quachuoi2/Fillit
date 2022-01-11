/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/11 18:33:45 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_all_tet(char ***arr); //rm
void	print_pos(t_tetris t); //rm

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
	int	i2;
	int	block_counter;

	block_counter = 0;
	i = 0;
	i2 = 0;
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
	int			i2;
	int a;
	t_coord		coord;

	i = 2;
	coord.y = 0;
	coord.x = 0;
	*map = map_gen(i);
	while (1)
	{
		a = comp1(map, i, coord, tet_list, 0);
		if (a != 1)
			{
				map_liberator(map, i++);
				*map = map_gen(i);
			}
		else
			break;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char		**map;
	char		c;
	int			i;
	t_tetris	*tet_list;
	t_ipt		tetri;

	if (argc <= 1)
		ft_putendl("usage: missing argument");
	else
	{
		tetri = read_input_file(argv[1]);
		tet_list = (t_tetris *)ft_memalloc(sizeof(t_tetris) * tetri.count);
		i = 0;
		c = 'A';
		while (i < tetri.count)
		{
			if (error_check(tetri.array[i]) == -1)
				return (-1);
			tet_list[i] = tet_mapping(tetri.array[i]);
			tet_list[i].c = c++;
			tet_list[i++].total = tetri.count;
		}
		map_print(map, fillit(&map, tetri.count, tet_list));
	}
	map_liberator(&map, map_print(map, fillit(&map, tet_list)));
	free(tet_list);
	i = 0;
	while (i < tetri.count)
	{
		free(tetri.array[i]);
		i++;
	}
	free(tetri.array);
	return (0);
}
