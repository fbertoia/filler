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
	while (points) // Itère sur tous les points.
	{
		i = 0;
		while (i < data->piece_x)
		{
			j = 0;
			while(j < data->piece_y) // Pour toutes les positions possibles de la pièce par rapport a ce point...
			{
				if ((distance = is_possible_and_distance(data, points->x - i, points->y - j))) // On rajoute les positions possibles dans notre liste ret.
				{
					create_point(&ret, points->x - i, points->y - j);
					if (!ret)
						return (NULL);
					add_distance(ret, distance);
				}
				j++;
			}
			i++;
		}
		if (ret)
			return (insert_sort(ret, func)); // Et on renvoie les positions possibles triées de la première pièce possiblement posée.
		points = points->next;
	}
	return (NULL);
}