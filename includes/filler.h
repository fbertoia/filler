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
	int		player_number;
	int		size_x;
	int		size_y;
	int		piece_x;
	int		piece_y;
	char	**board;
	char	**piece;
	char	*av;
}				t_d;

int		parse_first_line(char *line, char *av);
int		parse_board(char *line, t_d *data);
void	print_map(char **map);
int		parse_piece(char *line, t_d *data);
int		cmp(char *line, int *i, char c);
void	print_piece(char **piece);
int		delboard(t_d *data);
int		delpiece(t_d *data);


#endif
