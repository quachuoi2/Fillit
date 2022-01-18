/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
/*   Updated: 2022/01/18 16:52:43 by qnguyen          ###   ########.fr       */
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

int	surround(char *tet, int i2, int b_c)
{
	int	i;

	i = 1;
	if (tet[i2 + 1] != '#' && tet[i2 + 5] != '#'
		&& ((i2 > 0 && tet[i2 - 1] != '#') && (i2 > 4 && tet[i2 - 5] != '#')))
		return (0);
	if (b_c < 3)
	{
		while (i <= 5 && tet[i2 + i] != '#')
			i++;
		if (i == 6)
			return (0);
	}
	return (1);
}

int	error_check(t_input *tetri)
{
	int		i;
	int		i2;
	int		block_counter;
	char	**a;

	i = -1;
	a = tetri->array;
	while (++i < tetri->count)
	{
		block_counter = 0;
		i2 = -1;
		while (a[i][++i2] != '\0')
		{
			if ((a[i][i2] != '\n' && a[i][i2] != '#' && a[i][i2] != '.')
			|| (a[i][i2] == '\n' && (a[i][i2 + 1] == '\n' || i2 % 5 != 4))
			|| (a[i][i2] == '#' && surround(a[i], i2, block_counter) == 0)
			|| (a[i][0] == '\n'))
				return (free_tetri(tetri->count, tetri));
			block_counter += (a[i][i2] == '#');
		}
		if (i2 < 20 || block_counter != 4)
			return (free_tetri(tetri->count, tetri));
	}
	return (1);
}
