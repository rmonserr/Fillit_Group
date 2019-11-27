/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:35:47 by rmonserr          #+#    #+#             */
/*   Updated: 2019/11/14 16:35:49 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#define BUFF_SIZE 100

void	ft_input(char *buf, int start);
int		ft_valid(char *tetramin);

typedef struct	s_tetris
{
	char			tetramino_ID;
	int				tetramino[4][4];
	struct s_tetris *next;
}				t_tetris;

// typedef	struct	s_field
// {
// 	int x;
// 	int y;
// 	char **field[][];
// }				t_fiels;



#endif
