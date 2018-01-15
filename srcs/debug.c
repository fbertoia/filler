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
