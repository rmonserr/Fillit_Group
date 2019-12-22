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

void		ft_fillit(t_tetris *tetraminoes)
{
	char 		buffer[21];
	char 		*buf;
	int			file;
	int			start;
	char		*tmp;

	start = 0;
 	buf = ft_strnew(0);
	// if (argc == 2)
	// {
		file = (open ("tetraminoes.txt", O_RDONLY));
		while (read(file, buffer, 21))
		{
			tmp = buf;
			buf = ft_strjoin(tmp, buffer);
			ft_strdel(&tmp);
		}
		ft_set_zero(tetraminoes);
		ft_input(buf, start, tetraminoes);
		ft_solution(tetraminoes);
		close(file);
		ft_strdel(&buf);
	// }
	// else
	// 	write (1, "Error\n", 6);
}

int		main()
{
	t_tetris tetraminoes[27];

	ft_fillit(tetraminoes);
	return (0);
}
