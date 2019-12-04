/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:42:48 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/02 20:42:49 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lst_count(t_tetris *list)
{
	t_tetris	*tmp;
	int			counter;

	counter = 1;
	tmp = list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

int		ft_sqrt(t_tetris *list)
{
	int nb;
	int i;

	nb = ft_lst_count(list) * 4;
	i = 1;
	if (nb > 0)
	{
		while (nb != (i * i))
		{
			if (nb == i)
				return (0);
			i++;
		}
		return (i);
	}
	else
		return (0);
}

int		board_size(t_tetris *list)
{
	int		board_size;

	board_size = ft_sqrt(list);
	return (board_size);
}
