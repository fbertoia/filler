#include <filler.h>

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

int	init_fist_round(t_d *data)
{
	int		i;
	char	*tmp;
	i = 0;

	while (data->board[i])
	{
		tmp = data->board[i];
		while ((tmp = ft_strchr(tmp, data->us_max)))
		{
			if (!create_point(&(data->points), i, (int)(tmp - data->board[i])))
				return (0);
			tmp++;
		}
		i++;
	}
	return (1);
}

int	put_piece(t_d *data)
{
	t_p		*positions;

	if (data->first_round)
		if (!init_fist_round(data))
			return (0);

	calculate_all_distances(data);
	data->points = insert_sort(data->points, func); // On trie tous les points par distance.

	positions = create_pos_list(data); // On récupère la liste des pieces posables autour du meilleur point de la liste.

	if (!positions)
		return (0); // Plus de positions possibles !

	add_piece_to_board(data, positions);
	ft_printf("%d %d\n", positions->x, positions->y);
	return (1);
}
