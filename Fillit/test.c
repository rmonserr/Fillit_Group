#include <stdio.h>
# define A 0000111100000000

int		main()
{
	short a;
	a = A;
	printf ("0000000000001111 = %d\n", a);
	printf ("0000000000001111 * 16 = %d = 0000000011110000\n", a * 16);
	return (0);
}
