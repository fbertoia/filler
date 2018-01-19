#include <filler.h>

t_p	*create_pos_list(t_d *data)
{
	t_p	*points;
	t_p	*ret;
	int	i;
	int	j;
	int distance;

	ret = NULL;
	points = data->points;
	while (points)
	{
		i = 0;
		while (i < data->piece_x)
		{
			j = 0;
			while(j < data->piece_y)
			{
				if ((distance = is_possible_and_distance(data, points->x - i, points->y - j)))
				{
					create_point(&ret, points->x - i, points->y - j);
					if (!ret)
					{
						return (NULL);
					}
					add_distance(ret, distance);
				}
				else
				{
				}
				j++;
			}
			i++;
		}
		if (ret)
		{
			ret = insert_sort(ret, func);
			return (ret);
		}
		points = points->next;
	}
	return (NULL);
}