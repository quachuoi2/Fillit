/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/10 15:57:43 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_all_tet(char ***arr); //rm
void print_pos(t_tetris t); //rm

t_ipt	read_input_file(int fd)
{
	t_ipt	ipt;
	int		ret;

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
		if (tetri[i] == '#')
			block_counter++;
		i++;
	}
	if (i < 20 || block_counter != 4)
		return (-1);
	return (1);
}

int	fillit(char ***map, int count, t_tetris *tet_list)
{
	char		c;
	int			i;
	int			i2;

	i = 2;
	c = 'A';
	while (i < 26)
	{
		*map = map_gen(i);
		i2 = 0;
		while (i2 < count)
		{
			if (comp(map, i, tet_list[i2], c++) == 0)
			{
				c = 'A';
				map_liberator(map, i);
				break;
			}
			i2++;
		}
		if (i2 == count)
			break;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char		**map;
	char		c;
	int			fd;
	int			i;
	int			i2;
	t_tetris	*tet_list;
	t_ipt		tetri;

	if (argc <= 1)
		ft_putendl("usage: missing arguement");
	else
	{
		fd = open(argv[1], O_RDONLY);
		tetri = read_input_file(fd);
		tet_list = (t_tetris *)malloc(sizeof(t_tetris) * tetri.count);
		i = 0;
		while (i < tetri.count)
		{
			if (error_check(tetri.array[i]) == -1)
			{
				printf("no\n");
				return (-1);
			}
			tet_list[i] = tet_mapping(tetri.array[i]);
			i++;
		}
	}
	map_print(map, fillit(&map, tetri.count, tet_list));
	return (0);
}
