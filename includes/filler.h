#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

enum e_flag
{
	state_first_line,
	state_board,
	state_piece
};

typedef struct	s_d
{
	int	player_number;
	int	size_x;
	int	size_y;
}				t_d;

int	parse_first_line(char *line, char *av);
int parse_board_line(char *line, t_d *data);


#endif
