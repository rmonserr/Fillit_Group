/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:30:52 by rmonserr          #+#    #+#             */
/*   Updated: 2019/12/17 17:30:54 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_out_map(char **result)
{
	int		counter;

	counter = 0;
	if (!result)
	{
		ft_putendl("error");
		return ;
	}
	while (result[counter])
	{
		ft_putendl(result[counter]);
		counter++;
	}
}
