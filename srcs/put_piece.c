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
	t_p point;

	point.x = x;
	point.y = y;
	return (calculate_distance(data, &point, data->to_search));
}

int	is_possible_and_distance(t_d *data, int x, int y)
{
	int i;
	int j;
	int flag;
	int min;

	i = 0;
	flag = 0;
	min = -1;
	// printf("debut of x = %d and y = %d. piece_x = %d and piece_y = %d\n", x, y, data->piece_x, data->piece_y);
	while (flag >= 0 && i < data->piece_x)
	{
		j = 0;
		if (((y + j >= data->size_y || x + i >= data->size_x) && data->piece[i][j] == '*')
			|| ((y < 0 || x < 0) && data->piece[i][j] == '*'))
			flag = -1;
		while (flag >= 0 && j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
				min = min != -1 && min < calculate_distance_piece(data, x + i, y + j) ? min : calculate_distance_piece(data, x + i, y + j);
			if (x + i >= 0 && y + j >= 0 && x + i < data->size_x && y + j < data->size_y)
			{
				if (data->board[x + i][y + j] == data->us_max && data->piece[i][j] == '*')
					 // flag = ((flag == 1) ? -1 : 1);
				 {
					 // printf("overlapping for x = %d, y = %d, i = %d, j = %d, size_x = %d and size_y = %d && flag = %d\n", x, y, i, j, data->size_x, data->size_y, flag);
					 if (flag == 1)
					 	flag = -1;
					else
						flag = 1;
				 }
				 else
				 	// printf("not overlapping for x = %d, y = %d, i = %d and j = %d\n", x, y, i, j);
				if ((data->board[x + i][y + j] == data->other_min ||
					data->board[x + i][y + j] == data->other_max) && data->piece[i][j] == '*')
					flag = -1;
			}
			else
			{
				// printf("testing for i = %d and j = %d\n", i, j);
			}
			// printf("i = %d, j = %d\n", i, j);
			j++;
		}
		i++;
	}
	// if (flag == 1)
	// {
	// 	print_board_with_piece(data, x, y);
	// }
;	return (flag == 1 ? min : 0);
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
		dprintf(data->debug_fd, "testing point at %d-%d\n", points->x, points->y);
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
						dprintf(data->debug_fd, "malloc error\n");
						return (NULL);
					}
					add_distance(ret, distance);
				}
				else
				{
					dprintf(data->debug_fd, "Not possible for %d - %d\n", i, j);
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

void	add_piece_to_board(t_d *data, t_p *coords)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
				create_point(&(data->points), coords->x + i, coords->y + j);
			j++;
		}
		i++;
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
	t_p		*positions;

	i = 0;
	data->to_search = data->other_max;
	if (data->first_round)
	{
		data->to_search = data->other_max;
		while (data->board[i])
		{
			if ((tmp = ft_strchr(data->board[i], data->us_max)))
				if (!create_point(&(data->points), i, (int)(tmp - data->board[i])))
				{
					dprintf(data->debug_fd, "error 0 !\n");
					return (0);
				}
			i++;
		}
	}
	calculate_all_distances(data, data->to_search);
	// print_list(data->points);
	data->points = insert_sort(data->points, func);
	// print_list(data->points);
	positions = create_pos_list(data);
	if (!positions)
	{
		// print_map(data->board);
		// print_piece(data->piece);
		dprintf(data->debug_fd, "error 1\n");
		return (0);
	}
	// print_map(data->board);
	// print_piece(data->piece);
	// print_board_with_piece(data, positions->x, positions->y);
	dprintf(data->debug_fd, "%d-%d\n", positions->x, positions->y);
	add_piece_to_board(data, positions);
	ft_printf("%d %d\n", positions->x, positions->y);
	return (1);
}
