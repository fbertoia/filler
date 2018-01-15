#include <filler.h>

int	parse_first_line(char *line, char *av)
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

int parse_board_line(char *line, t_d *data)
{
	int		size_x;
	int		size_y;
	int		i;

	if (!ft_strnequ(line, "Plateau ", 8))
		return (-1);
	size_x = ft_atoi(line + 8);
	i = 8;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (-2);
		i++;
	}
	i++;
	size_y = ft_atoi(line + i);
	while (line[i] && line[i] != ':')
	{
		if (!ft_isdigit(line[i]))
			return (-3);
		i++;
	}
	if (line[i] != ':' || line[i + 1] != '\0')
		return (-4);
	if (size_x <= 0 || size_y <= 0 ||
		((data->size_x != -1 || data->size_y != -1) && (data->size_x != size_x || data->size_y != size_y)))
		{
			return (-5);
		}
	data->size_x = size_x;
	data->size_y = size_y;
	return (1);
}

/*
$$$ exec p1 : [./jcamhi.filler]
Plateau 15 17:
*/
