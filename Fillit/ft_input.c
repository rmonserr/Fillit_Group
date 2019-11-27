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

t_tetris	*new_list()
{
	t_tetris *new;

	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	new->next = NULL;
	return (new);
}

t_tetris	*to_list(char *str, char id, t_tetris *list)
{
	int		pos;
	int		x;
	int		y;

	pos = 0;
	x = 0;
	y = 0;
	while (str[pos])
	{
		if (str[pos] == '\n')
			pos++;
		if (str[pos] == '.')
			list->tetramino[x][y++] = 0;
		if (str[pos] == '#')
			list->tetramino[x][y++] = 1;
		pos++;
	}
	list->tetramino_ID = id;
	list->next = NULL;
	return (list);
}

void	ft_to_coords(char *str, int nlcounter, char id)
{
	int				pos;
	static t_tetris	*head;
	t_tetris		*tmp;

	if (ft_valid(str) == 0)
		return ; // change to exit
	if (!head)
		head = new_list();
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = to_list(str, id, tmp);
}

void	ft_input(char *buf, int start)
{
	char		tet_id;
	int			nlcounter;
	int			position;
	char		*str;
	char		*tmp;

	tmp = buf;
	tet_id = 'A';
	while (*tmp)
	{
		nlcounter = 0;
		position = 0;
		while (*tmp && nlcounter != 5)
		{
			if (*tmp == '\n')
				nlcounter++;
			tmp++;
			position++;
		}
		ft_to_coords((str = ft_strsub(buf, start, position - 1)),
			nlcounter, tet_id);
		tet_id += 1;
		start += 21;
	}
}
