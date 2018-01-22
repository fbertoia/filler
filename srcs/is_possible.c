#include <filler.h>

static int	point_is_possible(t_d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->size_x || y >= data->size_y)
		return (-1);
	if (data->board[x][y] == data->enemy_char)
		return (-1);
	if (data->board[x][y] == data->ally_char)
		return (1);
	return (0);
}

int			is_possible(t_d *data, int x, int y)
{
	int	i;
	int	j;
	int	flag;
	int	tmp;

	i = -1;
	flag = 0;
	while (++i < data->piece_x)
	{
		j = -1;
		while (++j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				tmp = point_is_possible(data, x + i, y + j);
				if (tmp == -1)
					return (0);
				else if (tmp == 1)
				{
					flag++;
					if (flag == 2)
						return (0);
				}
			}
		}
	}
	return (flag == 1);
}
