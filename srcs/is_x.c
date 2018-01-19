#include <filler.h>

int		is_surrounded_by_points(t_d *data, int x, int y)
{
	int flag;

	flag = 0;
	if (x - 1 < 0 || data->board[x - 1][y] == data->us_max || data->board[x - 1][y] == data->other_max)
		flag++;
	if (y - 1 < 0 || data->board[x][y - 1 ] == data->us_max  || data->board[x][y - 1] == data->other_max)
		flag++;
	if (x + 1 >= data->size_x || data->board[x + 1][y] == data->us_max  || data->board[x + 1][y] == data->other_max)
		flag++;
	if (y + 1 >= data->size_y || data->board[x][y + 1] == data->us_max  || data->board[x][y + 1] == data->other_max)
		flag++;
	return (!(flag == 4));
}