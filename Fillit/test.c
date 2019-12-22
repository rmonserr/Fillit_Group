#include <stdio.h>
#include "fillit.h"

void	print_arr(t_tetris *arr)
{
	int i = 0;

	while (i < 27)
	{
		printf("%c\n", arr[i].tetramino_id);
		i++;
	}
}

void	change_numbers(t_tetris *arr)
{
	int i = 0;

	while (i < 27)
	{
		arr[i].tetramino_id = 'A';
		i++;
	}
}

int		main()
{
	// int	arr[10] = {0};
	// print_arr(&arr[0]);

	t_tetris arr[27];
	change_numbers(arr);
	print_arr(arr);
}
