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

int			ft_valid(char *tetramin);

typedef struct	s_tetris
{
	char			tetramino_id;
	struct s_tetris *next;
	int				x[4];
	int				y[4];
}				t_tetris;

void		ft_input(char *buf, int start, t_tetris **head);
int			ft_board_size(t_tetris *list);
void		ft_solution(t_tetris *head);
char		**ft_insert_tetri(char **map, t_tetris *head, int size);
char		**ft_new_map(char **tetri_map, int size);
char		**ft_remove_tetri(char **map, t_tetris *head, int size);
void		ft_out_map(char **result, int size);
int			ft_lst_count(t_tetris *list);
void		ft_recursion_exit(t_tetris **head);
void		ft_recursion_exit(t_tetris **head);

#endif
