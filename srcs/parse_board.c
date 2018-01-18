#include <filler.h>

int				parse_first_line(char *line, char *av)
{
	if (!ft_strnequ("$$$ exec p", line, 10))
		return (-1);
	if (line[10] != '1' && line[10] != '2')
		return (-2);
	if (!ft_strnequ(" : [", line + 11, sizeof(" : [") - 1))
		return (-3);
	if (!ft_strnequ(line + 15, av, ft_strlen(av)))
		return (-4);
	if (!ft_strequ(line + 15 + ft_strlen(av), "]"))
		return (-5);
	return (line[10] - '0');
}

int				cmp(char *line, int *i, char c)
{
	while (line[*i] && line[*i] != c)
	{
		if (!ft_isdigit(line[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

static int		parse_board_line(char *line, t_d *data)
{
	int		size_x;
	int		size_y;
	int		i;

	if (!ft_strnequ(line, "Plateau ", 8))
		return (-1);
	size_x = ft_atoi(line + 8);
	i = 8;
	if (!cmp(line, &i, ' '))
		return (-2);
	i++;
	size_y = ft_atoi(line + i);
	if (!cmp(line, &i, ':'))
		return (-3);
	if (line[i] != ':' || line[i + 1] != '\0')
		return (-4);
	if (size_x <= 0 || size_y <= 0 || ((data->size_x != -1 ||
		data->size_y != -1) && (data->size_x != size_x
			|| data->size_y != size_y)))
		return (-5);
	data->size_x = size_x;
	data->size_y = size_y;
	return (1);
}

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

	j = 0;
	while (j < data->size_y && *tmp)
	{
		if (*tmp != '.' && *tmp != 'o' && *tmp != 'O'
				&& *tmp != 'x' && *tmp != 'X')
			return (0);
		if (*tmp == data->other_max && (data->first_round || data->board[i][j] != *tmp))
		{
			create_point(&(data->enemy_points), i, j);
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

static int		parse_board_other(t_d *data)
{
	char	*line;
	int		i;
	char	*tmp;
	int		k;

	i = 0;
	line = NULL;
	while (i < data->size_x && (k = get_next_line(0, &line)) > 0)
	{
		dprintf(data->log_fd, "%s\n", line);
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

static int		pieces_ok(char **board)
{
	void	*o;
	void	*x;
	int		i;

	o = NULL;
	x = NULL;
	i = 0;
	while (board[i])
	{
		if (!o)
			o = ft_strchr(board[i], 'O');
		if (!x)
			x = ft_strchr(board[i], 'X');
		i++;
	}
	if (!o || !x)
		return (0);
	return (1);
}

int				parse_2(t_d *data)
{
	if (parse_board_other(data) < 0)
	{
		ft_printf("Error: Board line error.\n");
		return (-5);
	}
	if (!pieces_ok(data->board))
	{
		ft_printf("Error: No pieces on board.\n");
		return (-6);
	}
	return (1);
}

int				parse_board(char *line, t_d *data)
{
	char	*l2;
	int		i;

	i = 0;
	l2 = NULL;
	if ((i = parse_board_line(line, data)) < 0)
	{
		ft_printf("Error: First board line not ok.\n");
		return (-1);
	}
	if (data->first_round)
	{
		if (!ft_create_board(data))
		{
			perror(data->av);
			return (-2);
		}
	}
	if (get_next_line(0, &l2) <= 0)
		return (-3);
	dprintf(data->log_fd, "%s\n", l2);
	if ((i = parse_board_second_line(l2, data)) < 0)
	{
		ft_printf("Error: Second board line not ok. i = %d\n", i);
		ft_memdel((void**)&l2);
		return (-4);
	}
	ft_memdel((void**)&l2);
	if (parse_2(data) < 0)
		return (-5);
	return (1);
}
