NAME = ../lib/libft.a

SRC_NAME = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_nb_words.c \
	  ft_len_split_word.c \
	  ft_fill_word.c \
	  ft_strsplit.c \
	  ft_excep_itoa.c \
	  ft_recur_power.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putnbr_octal.c \
	  ft_putlong_x_up.c \
	  ft_putnbr_x_up.c \
	  ft_putnbr_x_up_wp.c \
	  ft_putlong_long_x_up.c \
	  ft_putlong_long_x_low.c \
	  ft_memdup.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  bin_to_deci.c \
	  ft_itoa_base.c \
	  ft_itoa_base_long.c \
	  ft_itoa_base_u_long.c \
	  ft_itoa_base_u_long_maj.c \
	  ft_itoa_base_majuscule.c \
	  ft_itoa_base_majuscule_long.c \
	  ft_itoa_long.c \
	  ft_recur_power_long.c \
	  ft_putshort.c \
	  ft_putsigned_char.c \
	  ft_putlong.c \
	  ft_putlong_long.c \
	  ft_putlong_x_low.c \
	  ft_putintmax_t.c \
	  ft_putssize_t.c \
	  ft_putunsigned_long.c \
	  ft_putunsigned_long_long.c \
	  ft_putsize_t.c \
	  ft_putlong_x_low_wp.c \
	  ft_putascii.c \
	  ft_put_unsigned_ascii.c \
	  get_next_line.c

SRC_PATH = ./
OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
