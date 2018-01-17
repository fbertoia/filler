#include <filler.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char	*s;
	t_d		data;
	int		state;

	data.size_x = -1;
	data.piece_x = -1;
	data.size_y = -1;
	data.piece_y = -1;
	data.board = NULL;
	data.piece = NULL;
	data.first_round = 1;
	data.av = av[0];
	data.points = NULL;
	data.log_fd = open("./log", O_WRONLY | O_CREAT);
	state = state_first_line;

	while ((get_next_line(0, &s)) > 0)
	{
		dprintf(data.log_fd, "%s\n", s);
		if (state == state_first_line)
		{
			data.player_number = parse_first_line(s, av[0]);
			if (data.player_number < 0)
			{
				ft_putstr_fd("Parsing error : Invalid first line\n", 2);
				return (1);
			}
			if (data.player_number == 1)
			{
				data.us_min = 'o';
				data.us_max = 'O';
				data.other_min = 'x';
				data.other_max = 'X';
			}
			else
			{
				data.us_min = 'x';
				data.us_max = 'X';
				data.other_min = 'o';
				data.other_max = 'O';
			}
			state = state_board;
		}
		else if (state == state_board)
		{
			if (parse_board(s, &data) <= 0)
				return (1);
			state = state_piece;
		}
		else if (state == state_piece)
		{
			if (parse_piece(s, &data) <= 0)
				return (1);
			if (!put_piece(&data))
				return (1);
			state = state_board;
		}
		ft_memdel((void**)&s);
	}
	delboard(&data);
	return (0);
}
