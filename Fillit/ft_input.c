/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:09:39 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/18 13:09:41 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coords(t_tetris *tetraminoes, char *str, char id, int index)
{
	int			pos;
	int			counter;

	pos = 0;
	counter = 0;
	while (str[pos])
	{
		if (str[pos] == '#')
		{
			tetraminoes[index].x[counter] = pos % 5;
			tetraminoes[index].y[counter] = pos / 5;
			counter++;
		}
		pos++;
	}
	tetraminoes[index].tetramino_id = id;
}

void		ft_to_coords(char *str, char id, t_tetris *tetraminoes)
{
	int		index;

	index = 0;
	if (ft_valid(str) == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (tetraminoes[index].tetramino_id != '0')
		index++;
	coords(tetraminoes, str, id, index);
}

void		ft_input(char *buf, int start, t_tetris *tetraminoes)
{
	char		id;
	int			nl;
	int			pos;
	char		*str;
	char		*tmp;

	tmp = buf;
	id = 'A';
	while (*tmp)
	{
		nl = 0;
		pos = 0;
		while (*tmp && nl != 5)
		{
			if (*tmp == '\n')
				nl++;
			tmp++;
			pos++;
		}
		ft_to_coords((str = ft_strsub(buf, start, pos - 1)), id, tetraminoes);
		id += 1;
		start += 21;
		ft_strdel(&str);
	}
}
