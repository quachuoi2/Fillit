/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
/*   Updated: 2022/02/02 10:55:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	print_error(void)
{
	ft_putendl("error");
	return (-1);
}

int	free_tetri(int max, int outcome, t_input *tetri)
{
	while (max > outcome)
		ft_strdel(&(*tetri).array[max--]);
	if (outcome >= 0)
		return (1);
	free(tetri->array);
	return (0);
}

int	surround(char *tet)
{
	char	*m[4];
	int		i;
	int		n;

	i = -1;
	m[0] = tet;
	while (++i < 4)
	{
		m[i] = ft_strchr(m[i - (i > 0)], '#');
		m[i][0] = (char)(m[i] - tet + 'a');
	}
	n = 0;
	i = -1;
	while (++i < 4)
	{
		n += (m[i][0] < 20 + 'a' && ft_isalpha(m[i][1]))
			+(m[i][0] < 16 + 'a' && ft_isalpha(m[i][5]))
			+(m[i][0] > 0 + 'a' && m[i][-1] == '#')
			+(m[i][0] > 4 + 'a' && m[i][-5] == '#');
		m[i][0] = '#';
	}
	return (n > 5);
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
			|| (a[i][0] == '\n'))
				return (free_tetri(tetri->count - 1, -1, tetri));
			block_counter += (a[i][i2] == '#');
		}
		if (i2 < 20 || block_counter != 4 || surround(a[i]) == 0)
			return (free_tetri(tetri->count - 1, -1, tetri));
	}
	return (1);
}
