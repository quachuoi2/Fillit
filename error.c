/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
/*   Updated: 2022/01/16 16:35:19 by qnguyen          ###   ########.fr       */
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
	int				i;
	int				i2;
	int				block_counter;
	static int		bugs;
	char			**a;

	i = -1;
	a = tetri->array;
	while (++i < tetri->count && i2 <= 20)
	{
		block_counter = 0;
		i2 = -1;
		while (a[i][++i2] != '\0')
		{
			if ((a[i][i2] != '\n' && a[i][i2] != '#' && a[i][i2] != '.')
			|| (a[i][0] == '\n') || (a[i][i2] == '\n' && a[i][i2 + 1] == '\n')
			|| (a[i][i2] == '#' && a[i][i2 + 1] != '#' && a[i][i2 + 5] != '#'
			&& a[i][i2 - 1] != '#' && a[i][i2 - 5] != '#'))
				bugs = 1;
			block_counter += (a[i][i2] == '#');
		}
		if (i2 < 20 || block_counter != 4 || bugs == 1)
			return (free_tetri(i2, tetri));
	}
	return (1);
}
