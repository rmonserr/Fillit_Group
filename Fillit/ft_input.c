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

// t_tetris	*ft_newlst(int tetramino, char id)
// {
// 	t_tetris	*new;

// 	if (!(new = (t_tetris *)malloc(sizeof(t_tetris))))
// 		return (NULL);
// 	new->tetramino = tetramino;
// 	new->tetramino_ID = id;
// 	new->next = NULL;
// 	return (new);
// }

// t_tetris	*to_list(int *tetramino, char id)
// {
// 	t_tetris	*head;
// 	t_tetris	*tmp;

// 	// if (!head)
// 	head = ft_newlst(*tetramino, id);
// 	tmp = head;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp = ft_newlst(*tetramino, id);
// 	return (tmp);
// }

void	ft_to_numbers(char *str, int nlcounter, char id)
{
	int			num[16];
	int			num_count;
	int			str_count;

	num_count = 0;
	str_count = 0;
	if (ft_valid(str) == 0)
		return ; // change to exit
	else
	{
		while (str[str_count])
		{
			if (str[str_count] != '#' && str[str_count] != '.' &&
				str[str_count] != '\n')
				return ; // change to exit
			if (str[str_count] == '\n')
				str_count++;
			if (str[str_count] == '.')
				num[num_count] = 0;
			if (str[str_count] == '#')
				num[num_count] = 1;
			str_count++;
			num_count++;
		}
	}
	to_list(num, id);
}

char	*ft_input(char *buf)
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
		ft_to_numbers((str = ft_strsub(buf, 0, position - 1)),
			nlcounter, tet_id);
		tet_id += 1;
	}
	return (str);
}
