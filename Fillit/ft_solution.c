/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:34:33 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/27 14:34:35 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int		ft_to_map(t_tetris *head, char map[17][18], int size)
// {
// 	t_tetris	*tmp;
// 	int			x;
// 	int			y;

// 	tmp = head;
// 	while (tmp->next != NULL)
// 	{
// 		x = 0;
// 		y = 0;
// 		while (y < size)
// 		{
// 			while (x < size)
// 			{
// 				if (tmp->tetramino[y][x] == 1 && map[x][y] == '.')
// 					map[y][x] = tmp->tetramino_ID;
// 				x++;
// 			}
// 			x = 0;
// 			y++;
// 		}
// 		tmp = tmp->next;
// 		size++;
// 	}
// 	return (1);
// }

char	ft_to_dots(char map[17][18])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 17)
	{
		while (x < 17)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][17] = '\0';
		x = 0;
		y++;
	}
	return (map[16][17]);
}

void	ft_solution(t_tetris *head)
{
	char		map[17][18];
	int			size;
	int			ret;

	size = board_size(head);
	ft_to_dots(map);

	t_tetris	*tmp;
	int			x;
	int			y;

	tmp = head;
	while (tmp->next != NULL)
	{
		x = 0;
		y = 0;
		while (y < size - 1)
		{
			while (x < size - 1)
			{
				if (tmp->tetramino[y][x] == 1 && map[y][x] == '.')
					map[y][x] = tmp->tetramino_ID;
				x++;
			}
			x = 0;
			y++;
		}
		tmp = tmp->next;
		size++;
	}
	return ;
}
