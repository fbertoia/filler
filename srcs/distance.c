#include <filler.h>

int		calculate_distance_piece(t_d *data, int x, int y, t_p *objectives)
{
	t_p point;
	int	i;
	int	j;
	int	rez;

	i = 0;
	rez = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				point.x = x + i;
				point.y = y + j;
				rez += calculate_distance(&point, objectives);
			}
			j++;
		}
		i++;
	}
	return (rez);
}

int		calculate_distance(t_p *point, t_p *objectives) // Calcule la distance entre un point et tous les points ennemis.
{
	int	min;
	t_p	*tmp;

	tmp = objectives;
	min = -1;
	while (tmp)
	{
		if (min == -1 || (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y) < min)
			min = (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y);
		tmp = tmp->next;
	}
	return (min);
}
