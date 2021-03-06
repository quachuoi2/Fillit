/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/02/04 10:53:17 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_tet_size(t_tetris *tet)
{
	int		i;

	i = 0;
	(*tet).box[0][0] = 0;
	(*tet).box[0][1] = 0;
	(*tet).w_l[1] = 0;
	while (++i < 4)
		if ((*tet).box[i][1] > (*tet).w_l[1])
			(*tet).w_l[1] = (*tet).box[i][1];
	(*tet).w_l[0] = (*tet).box[3][0];
}

t_tetris	tet_mapping(char **t, int i, int total)
{
	t_tetris	tet;
	ssize_t		col;
	ssize_t		row;
	int			box_count;

	box_count = 0;
	row = 0;
	col = 0;
	tet.box[0][0] = 0;
	tet.box[0][1] = 0;
	tet.c = (char)(i + 'A');
	tet.ttl = total;
	while ((*t)[col])
	{
		if ((*t)[col] == '#')
		{
			tet.box[box_count][0] = row - tet.box[0][0];
			tet.box[box_count][1] = (col % 5) - tet.box[0][1];
			box_count++;
		}
		row += ((*t)[col++] == '\n');
	}
	get_tet_size(&tet);
	free(*t);
	return (tet);
}

int	read_input(t_input *ipt, int fd)
{
	ssize_t	ret;
	ssize_t	prev_ret;

	(*ipt).count = 0;
	prev_ret = 0;
	(*ipt).array = (char **)ft_memalloc(sizeof(char *) * (TETRIS_MAX + 1));
	while ((*ipt).count < 28)
	{
		(*ipt).array[(*ipt).count] = (char *)ft_memalloc(TETRIS_END + 1);
		ret = read(fd, (*ipt).array[(*ipt).count], TETRIS_END + 1);
		if (ret == 0 && prev_ret == 20 && ipt->count > 0)
			return (free_tetri((*ipt).count, (*ipt).count - 1, ipt));
		if (ret == 0 || ipt->count > 25
			|| (ret > 0 && (*ipt).array[(*ipt).count][ret - 1] != '\n')
			|| (ret == 21 && (*ipt).array[(*ipt).count][ret - 2] != '\n'))
			return (free_tetri((*ipt).count, -1, ipt));
		(*ipt).array[(*ipt).count][TETRIS_END] = '\0';
		prev_ret = ret;
		(*ipt).count++;
	}
	return (1);
}

ssize_t	fillit(char ***map, t_tetris *tet_list)
{
	ssize_t	i;

	i = (ssize_t)ft_sqrt(4 * tet_list[0].ttl);
	i = i + (i * i < (ssize_t)(4 * tet_list[0].ttl));
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
	ssize_t		size;
	t_input		tetri;
	t_tetris	tet_list[27];

	if (argc != 2)
		ft_putendl("usage: ./fillit filename");
	else
	{
		i = open(argv[1], O_RDONLY);
		if (i == -1 || !read_input(&tetri, i) || !error_check(&tetri)
			|| tetri.count <= 0)
			return (print_error());
		close(i);
		i = -1;
		while (++i < tetri.count)
			tet_list[i] = tet_mapping(&tetri.array[i], i, tetri.count);
		free(tetri.array);
		size = fillit(&map, tet_list);
		map_liberator(&map, map_printer(map, size));
	}
	return (0);
}
