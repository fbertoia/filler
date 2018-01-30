/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proximity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:44:33 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:44:35 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	calculate_proximity_2(t_p *point, t_d *data, int *i)
{
	if (point->y + 1 < data->size_y && data->board[point->x][point->y + 1] ==
		data->enemy_char)
		*i -= 4;
	if (point->x - 1 >= 0 && point->y - 1 >= 0 &&
		data->board[point->x - 1][point->y - 1] == data->enemy_char)
		*i -= 2;
	if (point->x - 1 >= 0 && point->y + 1 < data->size_y &&
		data->board[point->x - 1][point->y + 1] == data->enemy_char)
		*i -= 2;
	if (point->x + 1 < data->size_x && point->y + 1 < data->size_y &&
		data->board[point->x + 1][point->y + 1] == data->enemy_char)
		*i -= 2;
	if (point->x + 1 < data->size_x && point->y - 1 >= 0 &&
		data->board[point->x + 1][point->y - 1] == data->enemy_char)
		*i -= 2;
	return (*i);
}

int			calculate_proximity(t_p *point, t_d *data)
{
	int i;

	i = 0;
	if (point->x - 1 >= 0 && data->board[point->x - 1][point->y] ==
		data->enemy_char)
		i -= 4;
	if (point->y - 1 >= 0 && data->board[point->x][point->y - 1] ==
		data->enemy_char)
		i -= 4;
	if (point->x + 1 < data->size_x && data->board[point->x + 1][point->y] ==
		data->enemy_char)
		i -= 4;
	return (calculate_proximity_2(point, data, &i));
}
