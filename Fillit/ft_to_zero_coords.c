/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_zero_coords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:26:13 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/02 19:26:16 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_left_tetro(int a[4][4])
{
	if (a[0][0] == 1)
		return (1);
	else if ((a[1][0] == 1) && (a[0][1] == 1) && (a[0][3] != 1))
		return (1);
	else if ((a[1][0] == 1) && (a[0][2] == 1) && (a[0][3] != 1))
		return (1);
	else if ((a[2][0] == 1) && (a[0][1] == 1))
		return (1);
	else
		return (0);
}

t_tetris	*to_zero_coords(t_tetris *list)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (check_left_tetro(list->tetramino) != 1)
	{
		x = 0;
		y = 0;
		while (y < 4)
		{
			while (x < 4)
			{
				if (list->tetramino[y][x] == 1)
				{
					list->tetramino[y][x] = 0;
					list->tetramino[y][--x] = 1;
				}
				x++;
			}
			x = 0;
			y++;
		}
	}
	return (list);
}

