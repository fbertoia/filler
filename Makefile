# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/30 13:37:09 by fbertoia          #+#    #+#              #
#    Updated: 2018/01/30 15:08:20 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c parse_board.c parse_piece.c delete.c put_piece.c \
			sort.c list.c list_possible_pieces.c is_possible.c distance.c \
			proximity.c parse_board_2.c
OBJ_PATH = ./obj/
INC_PATH = ./libft/includes ./includes
SRC_PATH = ./srcs/
NAME = fbertoia.filler
CC = gcc
CFLAGS = -Wextra -Wall -Werror
LFLAGS = ./libft/libft.a
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)

INC = $(addprefix -I,$(INC_PATH))

all : $(NAME) $(NAME_CH)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -p $(OBJ_PATH) 2> /dev/null || true
	@make -C libft clean

fclean: clean
	@rm -fv $(NAME)
	@make -C libft fclean
	@rmdir lib 2> /dev/null || true

re: fclean all

.PHONY : all clean fclean re
