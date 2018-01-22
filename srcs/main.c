#include <filler.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char	*s;
	t_d		data;
	int		state;

	if (ac != 1)
		return (1);
	data.size_x = -1;
	data.piece_x = -1;
	data.size_y = -1;
	data.piece_y = -1;
	data.board = NULL;
	data.piece = NULL;
	data.first_round = 1;
	data.av = av[0];
	data.points = NULL;
	data.enemy_points = NULL;
	data.log_fd = open("./log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data.debug_fd = open("./debug", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	data.target.next = NULL;
	state = state_first_line;
	data.nbr_tours = 0;
	data.touched_enemy = 0;
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
				data.ally_char = 'O';
				data.enemy_char = 'X';
			}
			else
			{
				data.ally_char = 'X';
				data.enemy_char = 'O';
			}
			state = state_board;
		}
		else if (state == state_board)
		{
			if (parse_board(s, &data) <= 0)
			{
				return (2);
			}
			state = state_piece;
			// print_list(data.enemy_points);
		}
		else if (state == state_piece)
		{
			if (parse_piece(s, &data) <= 0)
				return (3);
			if (!put_piece(&data))
			{
				delboard(&data);
				ft_memdel((void**)&s);
				// while(1);
				return (4);
			}
			data.piece_x = -1;
			data.piece_y = -1;
			delpiece(&data);
			data.first_round = 0;
			state = state_board;
			dellist(&(data.enemy_points));
			data.nbr_tours++;
		}
		ft_memdel((void**)&s);
	}
	return (0);
}
