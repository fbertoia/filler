#include <filler.h>

void	calculate_all_distances(t_d *data, t_p *list) // Calcule les distances de tous les points allies par rapport à tous les points ennemis.
{
	while (list)
	{
		list->distance =	calculate_distance(data, list);
		list = list->next;
	}
}

int		calculate_distance_wrapper(t_d *data, int x, int y)
{
	t_p point;

	point.x = x;
	point.y = y;
	return (calculate_distance(data, &point));
}

void	add_distance(t_p *ret, int distance)
{
	while (ret->next)
		ret = ret->next;
	ret->distance = distance;
}

int		calculate_distance(t_d *data, t_p *point) // Calcule la distance entre un point et tous les points ennemis.
{
	int	min;
	t_p	*tmp;

	tmp = data->enemy_points;
	min = -1;
	while (tmp)
	{
		if (min == -1 || (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y) < min)
		{
			min = (point->x - tmp->x) * (point->x - tmp->x) + (point->y - tmp->y) * (point->y - tmp->y);
		}
		tmp = tmp->next;
	}
	return (min);
}
