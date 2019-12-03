#include <stdio.h>
#include <stdint.h>

int check_left_tetro(int a[4][4])
{
	if (a[0][0] == 1)
		return (1);
	else if ((a[1][0] == 1) && (a[0][1] == 1) && (a[0][3] != 1))
		return (1);
	else if ((a[1][0] == 1) && (a[0][2] == 1) && (a[0][3] != 1))
		return (1);
	else if ((a[2][0] == 1) && (a[0][1] == 1))
		return (1);
	else
		return (0);
}

int		main()
{
	int x = 0;
	int y = 0;
	int		a[4][4] =	{
							{0, 0, 0, 0},
							{0, 0, 1, 0},
							{0,	1, 1, 1},
						  	{0, 0, 0, 0}
						};
	while(check_left_tetro(a) != 1)
	{
		x = 0;
		y = 0;
		while (y < 4)
		{
			while (x < 4)
			{
				if (a[y][x] == 1)
				{
					a[y][x] = 0;
					a[y][--x] = 1;
				}
				x++;
			}
			x = 0;
			y++;
		}
	}

	while (x < 4)
	{
		y = 0;
		while(y < 4)
		{
			printf("%d", a[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}
