#include <filler.h>

static int		parse_board_second_line(char *line, t_d *data)
{
	char	c;
	int		i;

	i = 0;
	c = '0';
	if (!ft_strnequ(line, "    ", 4))
		return (-1);
	line += 4;
	while (*line == c)
	{
		c++;
		if (c > '9')
			c = '0';
		line++;
		i++;
	}
	if (*line)
		return (-2);
	if (i != data->size_y)
		return (-3);
	return (1);
}

int				ft_create_board(t_d *data)
{
	int	i;

	i = 0;
	if (data->board)
		return (1);
	else
	{
		if (!(data->board = (char**)malloc(sizeof(char*)
			* (data->size_x + 1))))
			return (0);
		while (i < data->size_x)
		{
			if (!((data->board)[i] = (char*)malloc(sizeof(char)
				* (data->size_y + 1))))
				return (0);
			i++;
		}
	}
	return (1);
}

int				ft_fill_board(t_d *data, char *tmp, int i)
{
	int j;
	int flag;

	j = 0;
	flag = 0;
	while (j < data->size_y && *tmp)
	{
		if (*tmp != '.' && *tmp != 'o' && *tmp != 'O'
				&& *tmp != 'x' && *tmp != 'X')
			return (0);
		if (*tmp == data->enemy_char && (data->first_round ||
			data->board[i][j] != *tmp))
		{
			add_new_point(&(data->enemy_points), i, j);
			if (data->first_round)
				data->enemy_starting_point = (t_p){NULL, 0, i, j};
		}
		(data->board)[i][j] = *tmp;
		j++;
		tmp++;
	}
	(data->board)[i][j] = '\0';
	if (j != data->size_y || *tmp)
		return (0);
	return (1);
}

int			parse_board_other(t_d *data)
{
	char	*line;
	int		i;
	char	*tmp;
	int		k;

	i = 0;
	line = NULL;
	while (i < data->size_x && (k = get_next_line(0, &line)) > 0)
	{
		if (ft_atoi(line) != i)
			return (-1);
		if ((tmp = ft_strchr(line, ' ')) == NULL)
			return (-2);
		tmp++;
		if (!ft_fill_board(data, tmp, i))
			return (-3);
		i++;
		ft_memdel((void**)&line);
	}
	data->board[i] = NULL;
	if (i != data->size_x)
		return (-4);
	return (1);
}

int				parse_board(char *line, t_d *data)
{
	char	*l2;
	int		i;

	i = 0;
	l2 = NULL;
	if ((i = parse_board_line(line, data)) < 0)
		return (par(-1, "Error: First board line not ok.\n"));
	if (data->first_round)
		if (!ft_create_board(data))
		{
			perror(data->av);
			return (-2);
		}
	if (get_next_line(0, &l2) <= 0)
		return (-3);
	if ((i = parse_board_second_line(l2, data)) < 0)
	{
		ft_memdel((void**)&l2);
		return (par(-4, "Error: Second board line not ok.\n"));
	}
	ft_memdel((void**)&l2);
	if (parse_2(data) < 0)
		return (-5);
	return (1);
}
