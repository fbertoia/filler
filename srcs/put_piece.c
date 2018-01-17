#include <filler.h>

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

int		calculate_distance_piece(t_d *data, int x, int y)
{
	int min;
	t_p point;

	point.x = x;
	point.y = y;
	return (calculate_distance(data, &point, data->to_search));
}

int	is_possible_and_distance(t_d *data, int x, int y)
{
	printf("is possible : testing for : %d %d\n", x, y);
	int i;
	int j;
	int flag;
	int min;

	i = 0;
	flag = 0;
	min = -1;
	while (x >= 0 && y >= 0 && (x + i < data->size_x ||
		data->board[x + i][y + j] != '*') && flag >= 0 && i < data->piece_x)
	{
		j = 0;
		while (flag >= 0 && j < data->piece_y && (y + j < data->size_y ||
			data->board[x + i][y + j] != '*'))
		{
			if (data->piece[i][j] == '*')
				min = min != -1 && min < calculate_distance_piece(data, x + i, y + j) ? min : calculate_distance_piece(data, x + i, y + j);
			if (data->board[x + i][y + j] == data->us_max && data->piece[i][j] == '*')
			{
				printf("when succeed :%d %d\n", x + i, y + j);
				 flag = (flag == 1) ? -1 : 1;
			}
			if ((data->board[x + i][y + j] == data->other_min ||
				data->board[x + i][y + j] == data->other_max) && data->piece[i][j] == '*')
				flag = -1;
			j++;
		}
		i++;
	}
	printf("flag = %d\n", flag);
	if (flag == 1)
	{
		print_board_with_piece(data, x, y);
	}
	return (flag == 1 ? min : 0);
}

void	add_distance(t_p *ret, int distance)
{
	while (ret->next)
		ret = ret->next;
	ret->distance = distance;
}

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
					printf("Create_pos_liste : les position de x = %d, y = %d\n", points->x - i, points->y - j);
					create_point(&ret, points->x - i, points->y - j);
					if (!ret)
						return (NULL);
					add_distance(ret, distance);
				}
				j++;
			}
			i++;
		}
		points = points->next;
	}
	return (ret);
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
	t_p		*positions;

	i = 0;
	data->to_search = data->other_min;
	if (data->first_round)
	{
		while (data->board[i])
		{
			if ((tmp = ft_strchr(data->board[i], data->us_max)))
				if (!create_point(&(data->points), i, (int)(tmp - data->board[i])))
					return (0);
			i++;
		}
		data->to_search = data->other_max;
	}
	calculate_all_distances(data, data->to_search);
	print_list(data->points);
	data->points = insert_sort(data->points, func);
	print_list(data->points);
	positions = create_pos_list(data);
	if (!positions)
		return (0);
	return (1);
}
