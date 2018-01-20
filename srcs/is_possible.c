#include <filler.h>


static int	point_is_possible(t_d *data, int x, int y)
{
	x = get_coord_board(x, data->size_x);
	y = get_coord_board(y, data->size_y);
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

	i = 0;
	flag = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				tmp = point_is_possible(data, x + i, y + j);
				if (tmp == -1)
					return (0);
				else if (tmp == 1)
				{
					flag++;
					if (flag == 2) // Touche plusieurs fois des points alliés.
						return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (flag == 1); // Retourne 0 si on a touche aucune piece alliée.
}