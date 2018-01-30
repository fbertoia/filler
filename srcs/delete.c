/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:01 by fbertoia          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:02 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		delpiece(t_d *data)
{
	int i;

	i = 0;
	while (i < data->piece_x)
	{
		free(data->piece[i]);
		i++;
	}
	free(data->piece);
	return (1);
}

int		delboard(t_d *data)
{
	int i;

	i = 0;
	while (i < data->size_x)
	{
		ft_memdel((void**)&(data->board)[i]);
		i++;
	}
	ft_memdel((void**)(&data->board));
	return (1);
}

void	dellist(t_p **list)
{
	t_p *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		ft_memdel((void**)list);
		*list = tmp;
	}
}

int		par(int ret, char *str)
{
	ft_putstr(str);
	return (ret);
}
