# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbertoia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 18:45:15 by fbertoia          #+#    #+#              #
#    Updated: 2017/12/29 23:17:06 by fbertoia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
INCLUDES = includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
DIR_PRINTF = ft_printf
DIR_LIBFT = libft

SRCS_LIBFT = $(addprefix $(DIR_LIBFT)/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c \
ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c \
ft_tolower.c ft_toupper.c ft_max.c ft_abs.c ft_itoa_base.c ft_strrev.c \
ft_strcapitalize.c ft_lstsize.c ft_strindex.c ft_strcdup.c ft_binsearch.c \
ft_lstadd_back.c ft_strnindex.c ft_strlcpy.c ft_sortstrings.c get_next_line.c)

OBJS_LIBFT = $(SRCS_LIBFT:$(DIR_LIBFT)/%.c=$(DIR_LIBFT)/obj/%.o)

all: $(NAME)

$(NAME): $(OBJS_LIBFT)
	@ar rsc $(NAME) $(OBJS_LIBFT) $(OBJS_PRINTF)

$(DIR_LIBFT)/obj/%.o: $(DIR_LIBFT)/%.c
	@mkdir -p libft/obj 2> /dev/null
	$(CC) -o $@ -c $(CFLAGS) $?

clean:
	rm -f $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft printf
