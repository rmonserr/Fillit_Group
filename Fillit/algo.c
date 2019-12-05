/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebulwer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:47:01 by ebulwer           #+#    #+#             */
/*   Updated: 2019/12/04 19:47:10 by ebulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fillit.h>

void    ft_sol(t_tetris *head)
{
    t_tetris	*tmp;
    int			size;
    int         **map;
    int         x;
    int         y;
    int         flag;

    flag = 0;
    x = -1;
    y = -1;
	tmp = head;
	size = board_size(tmp);

    //create map + bzero

    while (tmp->next != NULL)
    {
        while (!(tmp->tetramino[4][4]))  //find x, y
        {
            while (++y < 4)
            {
                while (++x < 4)
                {
                    if (tmp->tetramino[y][x] == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
            // check_for_map
            // ft_sol
            // запись на карту
        }
        tmp = tmp->next;
    }
}