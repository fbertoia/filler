/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:38 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:40 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
#include <unistd.h>

void	init_data(t_d *data, char *av)
{
	data->size_x = -1;
	data->piece_x = -1;
	data->size_y = -1;
	data->piece_y = -1;
	data->board = NULL;
	data->piece = NULL;
	data->first_round = 1;
	data->av = av;
	data->points = NULL;
	data->enemy_points = NULL;
	data->target.next = NULL;
	data->nbr_tours = 0;
	data->touched_enemy = 0;
	data->cheat_mode = 1;
}

int		state_fl(t_d *data, int *state, char *s)
{
	data->player_number = parse_first_line(s, data->av);
	if (data->player_number < 0)
	{
		ft_putstr_fd("Parsing error : Invalid first line\n", 2);
		return (0);
	}
	if (data->player_number == 1)
	{
		data->ally_char = 'O';
		data->enemy_char = 'X';
	}
	else
	{
		data->ally_char = 'X';
		data->enemy_char = 'O';
	}
	*state = state_board;
	return (1);
}

int		state_b(t_d *data, char *s, int *state)
{
	if (parse_piece(s, data) <= 0)
		return (0);
	if (!put_piece(data))
	{
		delboard(data);
		delpiece(data);
		ft_memdel((void**)&s);
		dellist(&(data->points));
		return (0);
	}
	delpiece(data);
	data->piece_x = -1;
	data->piece_y = -1;
	data->first_round = 0;
	*state = state_board;
	dellist(&(data->enemy_points));
	data->nbr_tours++;
	return (1);
}

int		free_mem(char **str, int a)
{
	ft_memdel((void**)str);
	return (a);
}

int		main(int ac, char **av)
{
	char	*s;
	t_d		data;
	int		state;

	(void)ac;
	init_data(&data, av[0]);
	state = state_first_line;
	while ((get_next_line(0, &s)) > 0)
	{
		if (state == state_first_line)
		{
			if (!state_fl(&data, &state, s))
				return (free_mem(&s, 1));
		}
		else if (state == state_board)
		{
			if (((state = state_piece) || 1) && parse_board(s, &data) <= 0)
				return (free_mem(&s, 2));
		}
		else if (state == state_piece)
			if (!state_b(&data, s, &state))
				return (3);
		ft_memdel((void**)&s);
	}
	return (0);
}
