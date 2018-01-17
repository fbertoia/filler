#include <filler.h>

int		func(void *a, void *b)
{
	t_p	*l1;
	t_p	*l2;

	l1 = (t_p*)a;
	l2 = (t_p*)b;
	return (l2->distance - l1->distance);
}

void	first_swap(t_gen **list, t_gen *current, t_gen **l2, t_gen *tmp)
{
	*list = current->next;
	*l2 = current;
	current->next = tmp;
}

void	*insert_sort(void *param, t_func comp)
{
	t_gen	*list;
	t_gen	*l2;
	t_gen	*tmp;
	t_gen	*current;

	list = (t_gen*)param;
	l2 = NULL;
	while (list)
	{
		tmp = l2;
		current = list;
		if (!tmp || (tmp && comp(list, tmp) >= 0))
			first_swap(&list, current, &l2, tmp);
		else
		{
			while (tmp && tmp->next && comp(current, tmp->next) <= 0)
				tmp = tmp->next;
			list = list->next;
			current->next = tmp->next;
			tmp->next = current;
		}
	}
	return (l2);
}
