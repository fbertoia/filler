#include <filler.h>

int	create_point(t_p **points, int x, int y)
{
	t_p *tmp;

	if (!(*points))
	{
		if (!(*points = (t_p *)malloc(sizeof(t_p))))
			return (0);
		tmp = *points;
	}
	else
	{
		tmp = *points;
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
