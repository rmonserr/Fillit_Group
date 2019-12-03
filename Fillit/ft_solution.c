/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:34:33 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/27 14:34:35 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_solution(t_tetris *head)
{
	t_tetris	*tmp;
	int			size;
	static int	elems;

	elems = 0;
	tmp = head;
	while (tmp->next != NULL)
		elems += 1;
	size = board_size(tmp);
}
