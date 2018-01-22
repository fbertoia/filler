#include <filler.h>

int			calculate_distance_top(t_d *data, int x, int y)
{
	t_p point;
	int	i;
	int	j;
	int	ret;
	t_p	top;

	top = (t_p){NULL, 0, 0, data->ally_starting_point.y};
	i = 0;
	ret = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				point = (t_p){NULL, 0, x + i, y + j};
				ret += calculate_distance(&point, &top);
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int			calculate_distance_piece(t_d *data, int x, int y)
{
	t_p point;
	int	i;
	int	j;
	int	ret;
	int	ret_prox;

	if (!(i = 0) && !data->touched_enemy)
		return (calculate_distance_top(data, x, y));
	ret = 0;
	ret_prox = 0;
	while (i < data->piece_x && !(j = 0))
	{
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				point = (t_p){NULL, 0, x + i, y + j};
				ret_prox += calculate_proximity(&point, data);
				ret += calculate_distance(&point, data->enemy_points);
			}
			j++;
		}
		i++;
	}
	return (ret_prox < 0 ? ret_prox : ret);
}

int			calculate_distance(t_p *point, t_p *target)
{
	int	min;
	t_p	*tmp;

	tmp = target;
	min = -1;
	while (tmp)
	{
		if (min == -1 || (point->x - tmp->x) * (point->x - tmp->x) +
		(point->y - tmp->y) * (point->y - tmp->y) < min)
		{
			min = (point->x - tmp->x) * (point->x - tmp->x) +
			(point->y - tmp->y) * (point->y - tmp->y);
		}
		tmp = tmp->next;
	}
	return (min);
}

int			check_frontiers_board(int size_x, int size_y, int x, int y)
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
