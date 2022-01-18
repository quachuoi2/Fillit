/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okinnune <okinnune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/18 21:26:49 by okinnune         ###   ########.fr       */
=======
/*   Updated: 2022/01/18 19:53:47 by qnguyen          ###   ########.fr       */
>>>>>>> 03dd6bd2a11f90e44111cece1833ba5329e6434d
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

int	surround3(char *tet)
{
	char	*m[4];
	int		i;
	int		n;

	i = -1;
	m[0] = tet;
	while (++i < 4)
	{
		m[i] = ft_strchr(m[i - (i > 0)], '#');
		m[i][0] = m[i] - tet + 'a';
	}
	n = 0;
	i = -1;
	while (++i < 4)
	{
		n += m[i][0] < 117 && (ft_isalpha(m[i][1]) || m[i][1] == '#');
		n += m[i][0] > 97 && (ft_isalpha(m[i][-1]) || m[i][-1] == '#');
		n += m[i][0] > 101 && (ft_isalpha(m[i][-5]) || m[i][-5] == '#');
		n += m[i][0] < 113 && (ft_isalpha(m[i][5]) || m[i][5] == '#');
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
				return (free_tetri(tetri->count, tetri));
			block_counter += (a[i][i2] == '#');
		}
		if (i2 < 20 || block_counter != 4 || surround3(a[i]) == 0)
			return (free_tetri(tetri->count, tetri));
	}
	return (1);
}

int	error_cheque(char *a)
{
	int		i2;
	int		block_counter;

	block_counter = 0;
	i2 = -1;
	while (a[++i2] != '\0')
	{
		if ((a[i2] != '\n' && a[i2] != '#' && a[i2] != '.')
		|| (a[i2] == '\n' && (a[i2 + 1] == '\n' || i2 % 5 != 4))
		|| (a[i2] == '#' && surround(a, i2, block_counter) == 0)
		|| (a[0] == '\n'))
			return (0);
		block_counter += (a[i2] == '#');
	}
	if (i2 < 20 || block_counter != 4)
		return (0);
	return (1);
}