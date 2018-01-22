#include <filler.h>

int			add_new_point(t_p **points, int x, int y)
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

t_p			*create_point(int x, int y, int distance)
{
	t_p	*ret;

	if (!(ret = (t_p*)malloc(sizeof(t_p))))
		return (NULL);
	ret->x = x;
	ret->y = y;
	ret->distance = distance;
	ret->next = NULL;
	return (ret);
}

void		add_point(t_p **list, t_p *point)
{
	t_p	*tmp;

	if (!point)
	{
		*list = NULL;
		return ;
	}
	if (!(*list))
	{
		*list = point;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = point;
}
