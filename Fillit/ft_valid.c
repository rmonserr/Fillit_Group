/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:10:16 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/18 13:10:17 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_connection_check(char *tetramino, int position)
{
	int		counter;
	int		connections;
	int		pos;

	connections = 0;
	pos = position;
	counter = 0;
	if (tetramino[++pos] == '#')
		connections++;
	pos = position;
	if (tetramino[pos + 5] == '#')
		connections++;
	pos = position;
	if (tetramino[--pos] == '#')
		connections++;
	pos = position;
	if (tetramino[position - 5] == '#')
		connections++;
	return (connections);
}

int		ft_valid(char *tetramino)
{
	int ret;
	int connections;
	int	sharp_counter;
	int position;

	position = 0;
	sharp_counter = 0;
	connections = 0;
	if ((ft_strlen(tetramino)) != 20)
		return (0);
	while (tetramino[position])
	{
		if (tetramino[position] == '#')
		{
			ret = ft_connection_check(tetramino, position);
			connections += ret;
			sharp_counter++;
		}
		position++;
	}
	if ((connections == 8 || connections == 6) && sharp_counter == 4)
		return (1);
	else
		return (0);
}
