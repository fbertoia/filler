#include <filler.h>

int	create_point(t_d *data, int x, int y)
{
	t_p *tmp;

	if (!data->points)
	{
		if (!(data->points = (t_p *)malloc(sizeof(t_p))))
			return (0);
		tmp = data->points;
	}
	else
	{
		tmp = data->points;
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

int		calculate_distance(t_d *data, t_p *point, char to_search)
{
	int	i;
	int	j;
	int	min;

	min = -1;
	i = 0;
	while (data->board[i])
	{
		j = 0;
		while(data->board[i][j])
		{
			if (data->board[i][j] == to_search)
			{
				if (min == -1 || (point->x - i) * (point->x - i) + (point->y - j) * (point->y - j) < min)
				{
					min = (point->x - i) * (point->x - i) + (point->y - j) * (point->y - j);
				}
			}
			j++;
		}
		i++;
	}
	return (min);
}

void	calculate_all_distances(t_d *data, char	to_search)
{
	t_p	*tmp;

	tmp = data->points;
	while (tmp)
	{
		tmp->distance =	calculate_distance(data, tmp, to_search);
		tmp = tmp->next;
	}
}

int	put_piece(t_d *data)
{
	// Si premier tour
		// ajouter le point d'acc a notre liste
		// aller vers le o majuscule
    //Sinon
	 	//calculer la distance entre chacun des points de notre liste chainee et les nouveaux points places
	// Trier la liste en fonction des distances
	// Tester toutes les positions possibles de la piece sur le point
	// Poser la piece a la meilleure positions
	// L'ajouter a la liste chainee
	int i;
	char *tmp;
	char	to_search;
	i = 0;
	to_search = data->other_min;
	if (data->first_round)
	{
		while (data->board[i])
		{
			if ((tmp = ft_strchr(data->board[i], data->us_max)))
				if (!create_point(data, i, (int)(tmp - data->board[i])))
					return (0);
			i++;
		}
		to_search = data->other_max;
	}
	calculate_all_distances(data, to_search);
	print_list(data->points);
	data->points = insert_sort(data->points, func);
	print_list(data->points);
	return (1);
}
