
char	*ft_to_numbers(char *str, int nlcount)
{
	int		sharp_counter;
	int		counter;
	char	*num;

	sharp_counter = 0;
	counter = 0;
	if (!(num = (char *)malloc((ft_strlen(str) - nlcount + 2) * sizeof(char))))
		return (0);
	while (str[sharp_counter])
	{
		if (str[sharp_counter] == '\n')
			sharp_counter++;
		else
		{
			if (str[sharp_counter] == '.')
				num[counter] = '0';
			if (str[sharp_counter] == '#')
				num[counter] = '1';
			counter++;
			sharp_counter++;
		}
	}
	return (num);
}

char	*ft_input(char *buf)
{
	int			nlcounter;
	int			position;
	char		*str;
	char		tetramino_id;
	char		*tmp;

	tetramino_id = 'A';
	tmp = buf;
	while (*tmp)
	{
		nlcounter = 0;
		position = 0;
		while (*tmp && nlcounter != 5)
		{
			if (*tmp == '\n')
				nlcounter++;
			tmp++;
			position++;
		}
		ft_to_numbers((str = ft_strsub(buf, 0, position - 1)), nlcounter);
		tetramino_id += 1;
	}
	free(tmp);
	return (str);
}

int		ft_valid(char *tetramino)
{
	int				position;
	int				sharp_counter;
	static int		connections;
	int				lenght;

	position = 0;
	connections = 0;
	sharp_counter = 0;
	if (((lenght = ft_strlen(tetramino)) != 20))
		return (0); //change to exit
	else
	{
		while (tetramino[position])
		{
			if (tetramino[position] == '#')
				sharp_counter++;
			position++;
		}
		position = 0;
		if (sharp_counter != 4)
			return (0); //change to exit
		else
			while (tetramino[position])
			{
				if (tetramino[position] == '#')
					connections = connections + ft_connection_check(tetramino, position); //while finding sharp - check connections
				position++;
			}
	}
	if (connections == 6 || connections == 8)
		return (1);
	else
		return (0);
}

oid    ft_sol(t_tetris *head)
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
