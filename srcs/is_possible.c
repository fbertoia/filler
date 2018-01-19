#include <filler.h>

int	is_possible_and_distance(t_d *data, int x, int y)
{
	int i;
	int j;
	int flag;
	int min;

	i = 0;
	flag = 0;
	min = 0;
	// min = -1;
	dprintf(data->debug_fd, "\n\nnew is possible : our point is %d %d\n", x, y);
	print_board_with_piece(data, x, y);
	while (flag >= 0 && i < data->piece_x)
	{
		j = 0;
		if (data->piece[i][j] == '*' &&
			(y + j >= data->size_y || x + i >= data->size_x || y + j < 0 || x + i < 0))
		{
			flag = -1;
		}
		while (flag >= 0 && j < data->piece_y)
		{
			if (data->piece[i][j] == '*' &&
				(y + j >= data->size_y || x + i >= data->size_x || y + j < 0 || x + i < 0))
			{
				flag = -1;
				break;
			}
			if (data->piece[i][j] == '*')
			{
				// min = min != -1 && min < calculate_distance_piece(data, x + i, y + j) ? min : calculate_distance_piece(data, x + i, y + j);
				min += calculate_distance_piece(data, x + i, y + j);
				dprintf(data->debug_fd, "min : %d\n", min);
			}

			if (x + i >= 0 && y + j >= 0 && x + i < data->size_x && y + j < data->size_y)
			{
				if (data->board[x + i][y + j] == data->us_max && data->piece[i][j] == '*')
				 {
					 if (flag == 1)
					 	flag = -1;
					else
						flag = 1;
				 }
				 else
				if ((data->board[x + i][y + j] == data->other_min ||
					data->board[x + i][y + j] == data->other_max) && data->piece[i][j] == '*')
					flag = -1;
			}
			j++;
		}
		i++;
	}
	return (flag == 1 ? min : 0);
}
