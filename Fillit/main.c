/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:35:19 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/14 16:35:23 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetris	*new_node()
{
	t_tetris *new;

	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	new->next = NULL;
	new->tetramino_id = 0;
	return (new);
}

void		ft_fillit(t_tetris **head)
{
	char 		buffer[21];
	char 		*buf;
	int			file;
	int			start;
	char		*tmp;

	start = 0;
	buf = ft_strnew(1);
	// if (argc == 2)
	// {
		file = (open ("tetraminoes.txt", O_RDONLY));
		while (read(file, buffer, 21))
		{
			tmp = buf;
			buf = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
		ft_input(buf, start, head);
		ft_recursion_exit(head);
		ft_solution(*head);
		close(file);
		ft_strdel(&buf);
	// }
	// else
	// 	write (1, "Error\n", 6);
}

int		main()
{
	t_tetris *head;

	head = new_node();
	ft_fillit(&head);
	return (0);
}
