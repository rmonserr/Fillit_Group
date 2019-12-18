/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:57:39 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/18 15:57:41 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_recursion_exit(t_tetris **head)
{
	t_tetris	*tmp;
	int			counter;

	counter = 0;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (!(tmp->next = (t_tetris *)malloc(sizeof(t_tetris))))
		return ;
	tmp = tmp->next;
	while (counter < 4)
	{
		tmp->x[counter] = 0;
		tmp->y[counter] = 0;
		counter++;
	}
	tmp->next = NULL;
}
