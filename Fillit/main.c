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

int		main()
{
	char 	buffer[1];
	char 	*buf;
	int		file;
	int		start;

	start = 0;
	buf = ft_strnew(1);
	// if (argc == 2)
	// {
		file = (open ("tetraminoes.txt", O_RDONLY));
		while (read(file, buffer, 1))
			buf = ft_strjoin(buf, buffer);
		ft_input(buf, start);
		close(file);
		free(buf);
	// }
	// else
	// 	write (1, "Error\n", 6);
	return (0);
}
