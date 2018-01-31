/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:44:41 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:49:26 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				add_new_point(&(data->points), data->cheat_mode ?
				modulo(coords->x + i, data->size_x) : coords->x + i,
				data->cheat_mode ? modulo(coords->y + i, data->size_y)
				: coords->y + j);
			j++;
		}
		i++;
	}
}

int		init_fist_round(t_d *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->board[i])
	{
		tmp = data->board[i];
		while ((tmp = ft_strchr(tmp, data->ally_char)))
		{
			if (!add_new_point(&(data->points), i, (int)(tmp - data->board[i])))
				return (0);
			data->ally_starting_point.x = i;
			data->ally_starting_point.y = (int)(tmp - data->board[i]);
			if (data->size_x > 20 || data->size_y > 20 ||
				data->ally_starting_point.x < data->enemy_starting_point.x)
			{
				data->touched_enemy = 1;
			}
			tmp++;
		}
		i++;
	}
	return (1);
}

int		touched_piece(t_d *data, t_p *position)
{
	int	i;
	int	j;
	t_p	point;

	i = 0;
	while (i < data->piece_x)
	{
		j = 0;
		while (j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				point = data->cheat_mode ? (t_p){NULL, 0, modulo(position->x +
					i, data->size_x), modulo(position->y + j, data->size_y)}
					: (t_p){NULL, 0, position->x + i, position->y + j};
				if (calculate_proximity(&point, data))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		put_piece(t_d *data)
{
	t_p		*possibilities;

	if (data->first_round)
		if (!init_fist_round(data))
			return (0);
	possibilities = list_possible_pieces(data);
	if (!possibilities)
		return (0);
	if (touched_piece(data, possibilities))
		data->touched_enemy = 1;
	add_piece_to_board(data, possibilities);
	ft_putnbr(possibilities->x);
	ft_putchar(' ');
	ft_putnbr(possibilities->y);
	ft_putchar('\n');
	dellist(&possibilities);
	return (1);
}
