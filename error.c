/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:10:31 by oskari            #+#    #+#             */
/*   Updated: 2022/01/16 03:32:15 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error_check(char *tetri)
{
	int	i;
	int	block_counter;

	block_counter = 0;
	i = 0;
	while (tetri[i] != '\0' && i <= 20)
	{
		if ((tetri[i] != '\n' && tetri[i] != '#' && tetri[i] != '.')
			|| (tetri[0] == '\n') || (tetri[i] == '\n' && tetri[i + 1] == '\n')
			|| (tetri[i] == '#' && tetri[i + 1] != '#' && tetri[i + 5] != '#'
				&& tetri[i - 1] != '#' && tetri[i - 5] != '#'))
			return (0);
		block_counter += (tetri[i] == '#');
		i++;
	}
	if (i < 20 || block_counter != 4)
		return (0);
	return (1);
}

int	print_error(void)
{
	ft_putendl("error");
	return (-1);
}
