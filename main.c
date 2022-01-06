/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/06 19:26:11 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include <stdio.h> //remooove


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
			free(array[i]);
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

	if (argc <= 1)
		ft_putendl("No arguments given!");
	else
	{
		fd = open(argv[1], O_RDONLY);
		arr = read_input_file(fd);
	}
	int i;
	i = 0;
	while (i < 20)
	{
		printf("tetris %d:\n%s",i , arr[i]);
		i++;
	}
	return (0);
}
