/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/19 14:23:03 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	tet_mapping(char **t, int i, int total)
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
	while ((*t)[col])
	{
		if ((*t)[col] == '#')
		{
			tet.box[box_count][0] = row;
			tet.box[box_count][1] = col % 5;
			box_count++;
		}
		if ((*t)[col] == '\n')
			row++;
		col++;
	}
	free(*t);
	return (tet);
}

int	read_input(t_input *ipt, char *file)
{
	int		ret;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	(*ipt).count = 0;
	(*ipt).array = (char **)ft_memalloc(sizeof(char *) * (TETRIS_MAX + 1));
	while ((*ipt).count < 28)
	{
		(*ipt).array[(*ipt).count] = (char *)ft_memalloc(TETRIS_END + 1);
		ret = read(fd, (*ipt).array[(*ipt).count], TETRIS_END + 1);
		if (ret == 0 && ipt->count > 0)
		{
			ft_strdel((*ipt).array + (*ipt).count);
			return (1);
		}
		if (ret == 0 || ipt->count > 25
			|| (ret > 0 && (*ipt).array[(*ipt).count][ret - 1] != '\n')
			|| (ret == 21 && (*ipt).array[(*ipt).count][ret - 2] != '\n'))
			return (free_tetri((*ipt).count, ipt));
		(*ipt).array[(*ipt).count][TETRIS_END] = '\0';
		(*ipt).count++;
	}
	return (1);
}

int	fillit(char ***map, t_tetris *tet_list)
{
	int			i;

	i = ft_sqrt(4 * tet_list[0].ttl);
	i = i + (i * i < (4 * tet_list[0].ttl));
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
	int			i;
	size_t		size;
	t_input		tetri;
	t_tetris	tet_list[27];
	if (argc != 2)
		ft_putendl("usage: ./fillit filename");
	else
	{
		if (!read_input(&tetri, argv[1]) || !error_check(&tetri)
			|| tetri.count <= 0)
			return (print_error());
		i = -1;
		while (++i < tetri.count)
			tet_list[i] = tet_mapping(&tetri.array[i], i, tetri.count);
		free(tetri.array);
		size = fillit(&map, tet_list);
		map_liberator(&map, map_printer(map, size));
	}
	return (0);
}
