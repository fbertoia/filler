SRC_NAME = main.c \
			parse_board.c \
			debug.c \
			parse_piece.c \
			delboard.c \
			put_piece.c \
			sort.c \
			list.c

OBJ_PATH = ./obj/

INC_PATH = ./includes ./libft/includes ./ft_printf/includes

SRC_PATH = ./srcs/

NAME = jcamhi.filler

CC = gcc
# CFLAGS =  -Wextra -Wall -g
CFLAGS =  -Wextra -Wall -g -fsanitize=address
LFLAGS = -lft -lftprintf
LIB_DIR=./lib/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix -I,$(INC_PATH))

all : LIB_RULE $(NAME) $(NAME_CH)

$(LCP_NAME) :

LIB_RULE:
	@mkdir -p $(LIB_DIR)

$(NAME) : $(OBJ)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) -L $(LIB_DIR) $(LFLAGS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -p $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean
	@make -C ft_printf clean

fclean: clean
	@rm -fv $(NAME)
	@make -C libft fclean
	@make -C ft_printf fclean
	@rmdir lib 2> /dev/null || true

re: fclean all

.PHONY : all clean fclean re
