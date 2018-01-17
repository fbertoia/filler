#include <filler.h>

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	print_piece(char **piece)
{
	int	i;

	i = 0;
	while (piece[i])
	{
		ft_putendl(piece[i]);
		i++;
	}
}

void	print_list(t_p *list)
{
	printf("-------------------------\n");
	while (list)
	{
		if (list->next)
			printf("%d->", list->distance);
		else
			printf("%d\n", list->distance);
		list = list->next;
	}
}
