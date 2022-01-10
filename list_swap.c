/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskari <oskari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:22:56 by oskari            #+#    #+#             */
/*   Updated: 2022/01/10 17:34:40 by oskari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void swap_tetris (t_tetris *t1, t_tetris *t2)
{
	t_tetris temp;

	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

t_tetris *swap(t_tetris *tet_list, int count)
{
	int i;

	i = 0;
	while (i < count - 1)
	{
		swap_tetris(&(tet_list[i]), &(tet_list[i + 1]));
		i++;
	}
	return (tet_list);
}
