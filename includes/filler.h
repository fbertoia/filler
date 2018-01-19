#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdio.h>
# include <ft_printf.h>

enum e_flag
{
	state_first_line,
	state_board,
	state_piece
};

typedef struct s_p
{
	struct s_p	*next;
	int			distance;
	int			x;
	int			y;
}				t_p;

typedef struct	s_d
{
	int		player_number;
	char	other_min;
	char	other_max;
	char	us_min;
	char	us_max;

	int		size_x;
	int		size_y;
	int		piece_x;
	int		piece_y;
	char	**board;
	char	**piece;
	char	*av;
	t_p		*points;
	t_p		*enemy_points;
	int		first_round;
	int		log_fd;
	int		debug_fd;
}				t_d;

typedef struct	s_gen
{
	struct s_gen	*next;
}				t_gen;

typedef int (*t_func)(void *a, void *b);

int		parse_first_line(char *line, char *av);
int		parse_board(char *line, t_d *data);
void	print_map(char **map);
int		parse_piece(char *line, t_d *data);
int		cmp(char *line, int *i, char c);
void	print_piece(char **piece);
int		delboard(t_d *data);
int		delpiece(t_d *data);
void	dellist(t_p **list);

int		put_piece(t_d *data);

void		*insert_sort(void *list, t_func comp);
int	func(void *a, void *b);
void	print_list(t_p *list);
void	print_board_with_piece(t_d *data, int x, int y);
int		create_point(t_p **points, int x, int y);
int		calculate_distance(t_d *data, t_p *point);
int	is_possible_and_distance(t_d *data, int x, int y);
t_p	*create_pos_list(t_d *data);

void	calculate_all_distances(t_d *data, t_p *list);
int		calculate_distance_piece(t_d *data, int x, int y);
void	add_distance(t_p *ret, int distance);

int		is_surrounded_by_points(t_d *data, int x, int y);

#endif
