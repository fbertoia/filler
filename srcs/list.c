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

int		us_between(t_d *data, t_p *us, t_p *enemy)
{
	int	x;
	int	y;
	int maxx;
	int maxy;

	if (us->x != enemy->x && us->y != enemy->y)
		return (0);
	x = us->x < enemy->x ? us->x : enemy->x;
	y = us->y < enemy->y ? us->y : enemy->y;
	maxx = us->x > enemy->x ? us->x : enemy->x;
	maxy = us->y > enemy->y ? us->y : enemy->y;
	while (x < maxx || y < maxy)
	{
		if (data->board[x][y] == data->us_max)
			return (1);
		if (x < maxx)
			x++;
		if (y < maxy)
			y++;
	}
	return (0);
}
