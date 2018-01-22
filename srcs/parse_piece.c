#include <filler.h>

static int		parse_piece_line(char *line, t_d *data)
{
	int		piece_x;
	int		piece_y;
	int		i;

	if (!ft_strnequ(line, "Piece ", 6))
		return (-1);
	piece_x = ft_atoi(line + 6);
	i = 6;
	if (!cmp(line, &i, ' '))
		return (-2);
	i++;
	piece_y = ft_atoi(line + i);
	if ((!cmp(line, &i, ':')))
		return (-3);
	if (line[i] != ':' || line[i + 1] != '\0')
		return (-4);
	if (piece_x <= 0 || piece_y <= 0)
		return (-5);
	data->piece_x = piece_x;
	data->piece_y = piece_y;
	return (1);
}

int				ft_create_piece(t_d *data)
{
	int	i;

	i = 0;
	if (!(data->piece = (char**)malloc(sizeof(char*)
		* (data->piece_x + 1))))
		return (0);
	while (i < data->piece_x)
	{
		if (!((data->piece)[i] = (char*)malloc(sizeof(char)
			* (data->piece_y + 1))))
			return (0);
		i++;
	}
	return (1);
}

int				ft_fill_piece(t_d *data, char *tmp, int i)
{
	int j;

	j = 0;
	while (j < data->piece_y && *tmp)
	{
		if (*tmp != '.' && *tmp != '*')
			return (0);
		(data->piece)[i][j] = *tmp;
		j++;
		tmp++;
	}
	(data->piece)[i][j] = '\0';
	if (j != data->piece_y || *tmp)
		return (0);
	return (1);
}

static int		parse_piece_other(t_d *data)
{
	char	*line;
	int		i;
	int		k;

	i = 0;
	line = NULL;
	while (i < data->piece_x && (k = get_next_line(0, &line)) > 0)
	{
		dprintf(data->log_fd, "%s\n", line);
		if (!ft_fill_piece(data, line, i))
			return (-3);
		i++;
		ft_memdel((void**)&line);
	}
	data->piece[i] = NULL;
	if (i != data->piece_x)
		return (-4);
	return (1);
}

int					parse_piece(char *line, t_d *data)
{
	int		i;

	i = 0;
	if (parse_piece_line(line, data) < 0)
	{
		ft_printf("Error: First piece line not ok.\n");
		return (-1);
	}
	if (!ft_create_piece(data))
	{
		perror(data->av);
		return (-2);
	}
	if ((i = parse_piece_other(data)) < 0)
	{
		ft_printf("Error: Second piece line not ok.");
		return (-4);
	}
	return (1);
}
