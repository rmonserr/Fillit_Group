
#include "fillit.h"
#include <stdio.h>

void		ft_fillit(t_tetris **head, char **argv)
{
	char 		buffer[21];
	char 		*buf;
	int			file;
	int			start;
	char		*tmp;

	start = 0;
	buf = ft_strnew(1);

		file = (open (argv[1], O_RDONLY));
		while (read(file, buffer, 21))
		{
			tmp = buf;
			buf = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		ft_input(buf, start, head);
		ft_recursion_exit(head);
		ft_solution(*head);
		close(file);
		free(buf);
}

int		main(int argc, char **argv)
{
	t_tetris *head;

	if (argc == 2)
		ft_fillit(&head, argv);
	else
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	return (0);
}
