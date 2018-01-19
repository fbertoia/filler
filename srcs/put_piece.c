#include <filler.h>

void	calculate_all_distances(t_d *data)
{
	t_p	*tmp;

	tmp = data->points;
	while (tmp)
	{
		tmp->distance =	calculate_distance(data, tmp);
		tmp = tmp->next;
	}
}

int		calculate_distance_piece(t_d *data, int x, int y)
{
	t_p point;

	point.x = x;
	point.y = y;
	return (calculate_distance(data, &point));
}

int		surrounded_by_points(t_d *data, int x, int y)
{
	int flag;

	flag = 0;
	if (x - 1 < 0 || data->board[x - 1][y] == data->us_max || data->board[x - 1][y] == data->other_max)
		flag++;
	if (y - 1 < 0 || data->board[x][y - 1 ] == data->us_max  || data->board[x][y - 1] == data->other_max)
		flag++;
	if (x + 1 >= data->size_x || data->board[x + 1][y] == data->us_max  || data->board[x + 1][y] == data->other_max)
		flag++;
	if (y + 1 >= data->size_y || data->board[x][y + 1] == data->us_max  || data->board[x][y + 1] == data->other_max)
		flag++;
	return (!(flag == 4));
}

void	add_distance(t_p *ret, int distance)
{
	while (ret->next)
		ret = ret->next;
	ret->distance = distance;
}

void	add_piece_to_board(t_d *data, t_p *coords)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
				create_point(&(data->points), coords->x + i, coords->y + j);
			j++;
		}
		i++;
	}
}

int	put_piece(t_d *data)
{
	int i;
	char *tmp;
	t_p		*positions;

	i = 0;
	if (data->first_round)
	{
		while (data->board[i])
		{
			tmp = data->board[i];
			while ((tmp = ft_strchr(tmp, data->us_max)))
			{
				if (!create_point(&(data->points), i, (int)(tmp - data->board[i])))
				{
					return (0);
				}
				tmp++;
			}
			i++;
		}
	}
	calculate_all_distances(data);
	data->points = insert_sort(data->points, func);
	positions = create_pos_list(data);
	if (!positions)
	{
		return (0);
	}
	add_piece_to_board(data, positions);
	ft_printf("%d %d\n", positions->x, positions->y);
	// dellist(position);
	return (1);
}
