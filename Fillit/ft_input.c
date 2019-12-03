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
	int			x;
	int			y;

	pos = 0;
	x = 0;
	y = 0;
	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (0);
	while (str[pos])
	{
		if (str[pos] == '\n')
			pos++;
		if (str[pos] == '.')
			new->tetramino[x][y++] = 0;
		if (str[pos] == '#')
			new->tetramino[x][y++] = 1;
		pos++;
	}
	to_zero_coords(new);
	new->tetramino_ID = id;
	new->next = NULL;
	return (new);
}

void		ft_to_coords(char *str, int nlcounter, char id)
{
	int				pos;
	static t_tetris	*head;
	t_tetris		*tmp;

	if (ft_valid(str) == 0)
		return ; // change to exit
	if (!head)
	{
		head = new_list(str, id);
		return ;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_list(str, id);
	// ft_solution(head);
}

void		ft_input(char *buf, int start)
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
		ft_to_coords((str = ft_strsub(buf, start, pos - 1)), nl, id);
		id += 1;
		start += 21;
	}
	free(str);
}
