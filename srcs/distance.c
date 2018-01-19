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

void	add_distance(t_p *ret, int distance)
{
	while (ret->next)
		ret = ret->next;
	ret->distance = distance;
}

