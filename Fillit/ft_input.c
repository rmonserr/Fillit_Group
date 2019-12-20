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

t_tetris	*new_list(char *str, char id)
{
	t_tetris	*new;
	int			pos;
	int			counter;

	pos = 0;
	counter = 0;
	if (!str || !id)
		return (NULL);
	if (!(new = (t_tetris *)malloc(sizeof(t_tetris)))) //allocate mem
		return (NULL);
	while (str[pos])
	{
		if (str[pos] == '#')
		{
			new->x[counter] = pos % 5;
			new->y[counter] = pos / 5;
			counter++;
		}
		pos++;
	}
	new->tetramino_id = id;
	new->next = NULL;
	return (new);
}

void		ft_to_coords(char *str, char id, t_tetris **head)
{
	t_tetris		*tmp;

	if (ft_valid(str) == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (!(*head))
	{
		*head = new_list(str, id);
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_list(str, id);
}

void		ft_input(char *buf, int start, t_tetris **head)
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
		ft_to_coords((str = ft_strsub(buf, start, pos - 1)), id, head); //allocaate mem
		id += 1;
		start += 21;
		ft_strdel(&str);
	}
}
