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

int		ft_check_tetri(char **tetri_map, t_tetris *head, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (head->y[i] < size && head->x[i] < size &&
				tetri_map[head->y[i]][head->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_change_tetri(t_tetris **head, int x, int y)
{
	int		pos_x;
	int		pos_y;
	int		counter;

	pos_x = 100;
	pos_y = 100;
	counter = 0;
	while (counter < 4)
	{
		if ((*head)->x[counter] < pos_x)
			pos_x = (*head)->x[counter];
		if ((*head)->y[counter] < pos_y)
			pos_y = (*head)->y[counter];
		counter++;
	}
	counter--;
	while (counter >= 0)
	{
		(*head)->x[counter] = (*head)->x[counter] - pos_x + x;
		(*head)->y[counter] = (*head)->y[counter] - pos_y + y;
		counter--;
	}
}

char	**ft_algo(char **tetri_map, t_tetris *head, int size)
{
	int		x;
	int		y;
	char	**map;

	if (head->next == NULL)
		return (tetri_map);
	map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_change_tetri(&head, x, y);
			if (ft_check_tetri(tetri_map, head, size))
				map = ft_algo(ft_insert_tetri(tetri_map, head, size),
					head->next, size);
			if (map)
				return (map);
			tetri_map = ft_remove_tetri(tetri_map, head, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solution(t_tetris *head)
{
	char		**result;
	char		**tetri_map;
	int			size;

	tetri_map = NULL;
	size = 2;
	result = NULL;
	tetri_map = ft_new_map(tetri_map, size);
	while (!(result = ft_algo(tetri_map, head, size)))
	{
		size++;
		ft_memdel((void **)tetri_map);
		tetri_map = ft_new_map(tetri_map, size);
	}
	ft_out_map(result, size);
}
