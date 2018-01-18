#include <filler.h>

int	create_point(t_p **points, int x, int y)
{
	t_p *tmp;

	if (!(*points))
	{
		if (!(*points = (t_p *)malloc(sizeof(t_p))))
			return (0);
		tmp = *points;
	}
	else
	{
		tmp = *points;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = (t_p *)malloc(sizeof(t_p))))
			return (0);
		tmp = tmp->next;
	}
	tmp->x = x;
	tmp->y = y;
	tmp->distance = -1;
	tmp->next = NULL;
	return (1);
}

int		calculate_distance(t_d *data, t_p *point)
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
