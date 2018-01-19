#include <filler.h>

void	print_board(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		ft_putendl(board[i]);
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
			printf("[%d][%d]%d->", list->x, list->y, list->distance);
		else
			printf("[%d][%d]%d\n", list->x, list->y, list->distance);
		list = list->next;
	}
	printf("-------------------------\n");
}

void	print_board_with_piece(t_d *data, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < data->size_x)
	{
		j = 0;
		while (j < data->size_y)
		{
			if (j >= y && j < y + data->piece_y && i >= x && i < x + data->piece_x)
			{
				if (data->piece[i - x][j - y] == '*')
				{
					// dprintf(data->debug_fd, "*");
				}
				else
				{
					// dprintf(data->debug_fd, "%c", data->board[i][j]);
				}
			}
			else
			{
				// dprintf(data->debug_fd, "%c", data->board[i][j]);
			}
			j++;
		}
		// dprintf(data->debug_fd, "\n");
		i++;
	}
}
