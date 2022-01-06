/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:20:41 by okinnune          #+#    #+#             */
/*   Updated: 2022/01/06 12:24:05 by okinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fillit.h"
#include <stdio.h> //remooove
#include <fcntl.h>

char *read_input_file (char *filename)
{
	int fd;
	char *line;
	char *temp;
	char *array[32];
	int a_count;

	fd = open(filename, O_RDONLY);
	temp = NULL;
	a_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line = ft_strjoin(line, "\n");
		if (temp == NULL)
			temp = ft_strdup(line);
		else if (ft_strcmp("\n", line) != 0)
			temp = ft_strjoin(temp, line);
		if (ft_strcmp("\n", line) == 0) //OR file ends
		{
			array[a_count] = ft_strdup(temp);
			a_count++;
			//printf("TEMP= \n%s", temp);
			ft_strdel(&temp);
		}
	}
	printf("FILE CONTENTS 0= \n%s\n", array[0]);
	printf("FILE CONTENTS 1= \n%s", array[1]);
	return (temp);
}

int		main (int argc, char **argv)
{
	char *input;

	if (argc <= 1)
		ft_putendl("No arguments given!");
	else
	{
		input = read_input_file(argv[1]);
	}
}	