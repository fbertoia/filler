/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:16 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:18 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			modulo(int a, int mod)
{
	a %= mod;
	if (a < 0)
		a += mod;
	return (a);
}

static int	point_is_possible(t_d *data, int x, int y)
{
	if (data->cheat_mode)
	{
		x = modulo(x, data->size_x);
		y = modulo(y, data->size_y);
	}
	else if (x < 0 || y < 0 || x >= data->size_x || y >= data->size_y)
		return (-1);
	if (data->board[x][y] == data->enemy_char)
		return (-1);
	if (data->board[x][y] == data->ally_char)
		return (1);
	return (0);
}

int			is_possible(t_d *data, int x, int y)
{
	int	i;
	int	j;
	int	flag;
	int	tmp;

	i = -1;
	flag = 0;
	while (++i < data->piece_x)
	{
		j = -1;
		while (++j < data->piece_y)
		{
			if (data->piece[i][j] == '*')
			{
				tmp = point_is_possible(data, x + i, y + j);
				if (tmp == -1)
					return (0);
				else if (tmp == 1)
					if (++flag == 2)
						return (0);
			}
		}
	}
	return (flag == 1);
}
