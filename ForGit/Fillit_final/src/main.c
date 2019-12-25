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

void		ft_fillit(t_tetris *tetraminoes, char **argv)
{
	char 		buffer[1000000];
	char 		*buf;
	int			file;
	char		*tmp;

 	buf = ft_strnew(0);
	file = (open (argv[1], O_RDONLY));
	while (read(file, buffer, 100000))
	{
		tmp = buf;
		buf = ft_strjoin(tmp, buffer);
		ft_strdel(&tmp);
	}
	ft_set_zero(tetraminoes);
	ft_input(buf, tetraminoes);
	ft_solution(tetraminoes);
	close(file);
	ft_strdel(&buf);
}

int		main(int argc, char **argv)
{
	t_tetris tetraminoes[27];

	if (argc == 2)
		ft_fillit(tetraminoes, argv);
	else
	{
		write (1, "Usage: ./Fillit [tetraminoes]\n", 30);
		exit(1);
	}
	return (0);
}
