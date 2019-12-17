/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:15:00 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/17 18:15:28 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_recursion_exit(t_tetris **head)
{
	t_tetris *tmp;

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (!(tmp->next = (t_tetris *)malloc(sizeof(t_tetris))))
		return ;
	tmp = tmp->next;
}
