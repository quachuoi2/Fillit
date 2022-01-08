/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/08 18:26:11 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //remooove

char	**read_input_file(int fd)
{
	char	**array;
	int		ret;
	int		i;

	i = 0;
	array = (char **)malloc(sizeof(char *) * TETRIS_MAX);
	while (i < 26)
	{
		array[i] = (char *)malloc(sizeof(char) * TETRIS_END + 1);
		ret = read(fd, array[i], TETRIS_END + 1);
		if (ret == 0)
		{
			ft_strdel(array + i);
			return (array);
		}
		array[i++][TETRIS_END] = '\0';
	}
	return (array);
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

int	main(int argc, char **argv)
{
	char	**arr;
	int		fd;
	int		i;

	if (argc <= 1)
		ft_putendl("usage: missing arguement");
	else
	{
		fd = open(argv[1], O_RDONLY);
		arr = read_input_file(fd);
	}
	i = 0;
	while (arr[i] != NULL)
	{
		if (error_check(arr[i]) == -1)
		{
			printf("no\n");
			return (-1);
		}
		i++;
	}
	i = 0;
	while (arr[i] != NULL)
	{
		printf("tetri %d:\n%s", i, arr[i]);
		i++;
	}
	return (0);
}
