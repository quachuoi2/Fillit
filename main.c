/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/10 18:26:24 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_all_tet(char ***arr); //rm
void	print_pos(t_tetris t); //rm

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

int	fillit(char ***map, int count, t_tetris *tet_list)
{
	int			i;
	int			i2;
	int			sw_count;

	i = 2;
	i2 = 0;
	while (i < 26)
	{
		*map = map_gen(i);
		i2 = 0;
		sw_count = 0;
		while (i2 < count && sw_count < count - 1)
		{
			if (comp(map, i, tet_list[i2]) == 0)
			{
				tet_list = swap(tet_list, count);
				sw_count++;
				//printf("SWAPPED LIST AROUND %i, MAP SIZE %i\n", sw_count, i);
				/*if (sw_count >= count - 1)
					map_liberator(map, i);*/
				i2 = -1;
			}
			i2++;
		}
		if (i2 == count)
			break ;
		i++;
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
		tetri = read_input_file(open(argv[1], O_RDONLY));
		tet_list = (t_tetris *)malloc(sizeof(t_tetris) * tetri.count);
		i = 0;
		printf("TETRI COUNT %i\n", tetri.count);
		while (i < tetri.count)
		{
			if (error_check(tetri.array[i]) == -1)
				return (-1);
			tet_list[i] = tet_mapping(tetri.array[i], i);
			i++;
		}
		map_print(map, fillit(&map, tetri.count, tet_list));
	}
	return (0);
}
