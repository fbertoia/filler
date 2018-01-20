#include <filler.h>

int		calculate_distance_piece(t_d *data, int x, int y)
{
	t_p point;
	int	i;
	int	j;
	int	ret;
	int	ret_prox;

	i = 0;
	ret = 0;
	ret_prox = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				point.x = get_coord_board(x + i, data->size_x);
				point.y = get_coord_board(y + j, data->size_;
				ret_prox += calculate_proximity(&point, data);
				ret += calculate_distance(&point, data->enemy_points);
			}
			j++;
		}
		i++;
	}
	return (ret_prox < 0 ? ret_prox : ret);
}

int		calculate_distance(t_p *point, t_p *target) // Calcule la distance entre un point et tous les points ennemis.
{
	int	min;
	t_p	*tmp;

	tmp = target;
	min = -1;
	while (tmp)
	{
		if (min == -1 || (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y) < min)
			min = (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y);
		tmp = tmp->next;
	}
	return (min);
}

int		check_frontiers_board(int size_x, int size_y, int x, int y)
{
	if (x >= size_x)
		return (0);
	if (x < 0)
		return (0);
	if (y >= size_y)
		return (0);
	if (y < 0)
		return (0);
	return (1);
}

int		calculate_proximity(t_p *point, t_d *data) // Calcule la distance entre un point et tous les points ennemis.
{
	int i;

	i = 0;
	if (point->x - 1 >= 0 && data->board[point->x - 1][point->y] == data->enemy_char)
		i -= 4;
	if (point->y - 1 >= 0 && data->board[point->x][point->y - 1] == data->enemy_char)
		i -= 4;
	if (point->x + 1 < data->size_x && data->board[point->x + 1][point->y] == data->enemy_char)
		i -= 4;
	if (point->y + 1 < data->size_y && data->board[point->x][point->y + 1] == data->enemy_char)
		i -= 4;
	if (point->x - 1 >= 0 && point->y - 1 >= 0 && data->board[point->x - 1][point->y - 1] == data->enemy_char)
		i -= 2;
	if (point->x - 1 >= 0 && point->y + 1 < data->size_y && data->board[point->x - 1][point->y + 1] == data->enemy_char)
		i -= 2;
	if (point->x + 1 < data->size_x && point->y + 1 < data->size_y && data->board[point->x + 1][point->y + 1] == data->enemy_char)
		i -= 2;
	if (point->x + 1 < data->size_x && point->y - 1 >= 0 && data->board[point->x + 1][point->y - 1] == data->enemy_char)
		i -= 2;
	return (i);
}

int		calculate_cross(t_d *data, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (check_frontiers_board(data->piece_x, data->piece_y, i, j) && (data->piece[i][j] == '*'))
				if (check_frontiers_board(data->size_x, data->size_y, x + i + 1, y + j) && (data->board[x + i + 1][y + j] == data->enemy_char))
					if (check_frontiers_board(data->size_x, data->size_y, x + i, y + j + 1) && (data->board[x + i][y + j + 1] == data->enemy_char))
						if (check_frontiers_board(data->piece_x, data->piece_y, i + 1, j + 1) && (data->piece[i + 1][j + 1] == '*'))
							return (1);
			if (check_frontiers_board(data->size_x, data->size_y, x + i, y + j) && (data->board[x + i][y + j] == data->enemy_char))
				if (check_frontiers_board(data->piece_x, data->piece_y, i + 1, j) && (data->piece[i + 1][j] == '*'))
					if (check_frontiers_board(data->piece_x, data->piece_y, i, j + 1) && (data->piece[i][j + 1] == '*'))
						if (check_frontiers_board(data->size_x, data->size_y, x + i + 1, y + j + 1) && (data->board[x + i + 1][y + j + 1] == data->enemy_char))
							return (1);
			j++;
		}
		i++;
	}
	return (0);
}
