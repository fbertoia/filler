#include <filler.h>

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
	return (1);
}
