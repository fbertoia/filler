/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_possible_pieces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:29 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:31 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_p	*list_possible_pieces(t_d *data)
{
	t_p	*possibilities;
	int	x;
	int	y;

	possibilities = NULL;
	x = data->size_x - 1;
	while (x >= -1 * data->piece_x)
	{
		y = data->size_y - 1;
		while (y >= -1 * data->piece_y)
		{
			if (is_possible(data, x, y))
			{
				add_point(&possibilities, create_point(x, y,
					calculate_distance_piece(data, x, y)));
				if (!possibilities)
					return (NULL);
			}
			y--;
		}
		x--;
	}
	possibilities = insert_sort(possibilities, func);
	return (possibilities);
}
