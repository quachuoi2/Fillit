/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
/*   Updated: 2022/01/16 16:02:56 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	print_error(void)
{
	ft_putendl("error");
	return (-1);
}

int	free_tetri(int i, t_input *tetri)
{
	while (i >= 0)
		free(tetri->array[i--]);
	free(tetri->array);
	return (0);
}

int	error_check(t_input *tetri)
{
	int	i;
	int	i2;
	int	block_counter;
	int	bugs;

	i2 = 0;
	bugs = 0;
	while (i2 < tetri->count)
	{
		block_counter = 0;
		i = 0;
		while (tetri->array[i2][i] != '\0' && i <= 20)
		{
			if ((tetri->array[i2][i] != '\n' && tetri->array[i2][i] != '#' && tetri->array[i2][i] != '.')
				|| (tetri->array[i2][0] == '\n') || (tetri->array[i2][i] == '\n' && tetri->array[i2][i + 1] == '\n')
				|| (tetri->array[i2][i] == '#' && tetri->array[i2][i + 1] != '#' && tetri->array[i2][i + 5] != '#'
					&& tetri->array[i2][i - 1] != '#' && tetri->array[i2][i - 5] != '#'))
				bugs = 1;
			block_counter += (tetri->array[i2][i] == '#');
			i++;
		}
		if (i < 20 || block_counter != 4 || bugs == 1)
			return (free_tetri(i, tetri));
		i2++;
	}
	return (1);
}
