#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "./ft_printf.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFF_SIZE 13
# define READ_LINE 1
# define READ_ERROR -1
# define READ_OVER 0

typedef struct	s_liste
{
	void			*content;
	size_t			content_size;
	struct s_liste	*next;
}				t_liste;


typedef struct      s_gnl
{
    char            *line;
    int             fd;
    struct s_gnl    *next;
}                   t_gnl;


int				bin_to_deci(char *nbr);
int				ft_len_nb(unsigned int nb, int base);
int				ft_len_nb_long(long long nb, int base);
char			*ft_itoa_base(unsigned int nb, int base);
char			*ft_itoa_base_long(long long nb, int base);
char			*ft_itoa_base_majuscule(unsigned int nb, int base);
char			*ft_itoa_base_majuscule_long(long long nb, int base);
void			*ft_memset(void *tab, int n, size_t len);
void			ft_bzero(void *tab, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int n, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int n, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
int				ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, unsigned int n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dst, const char *src, int n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char*));
void			ft_striteri(char *str, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_nb_words(const char *str, char c);
int				ft_len_split_word(const char *str, char c);
void			ft_fill_word(char *dest, const char *src, int length);
char			**ft_strsplit(const char *str, char c);
char			*ft_strtrim(const char *s);
char			*ft_excep_itoa(int n);
long			ft_recur_power(int nb, int pow);
long			ft_recur_power_long(long long nb, int pow);
char			*ft_itoa(int n);
char			*ft_itoa_long(long long n);
char			*ft_itoa_base_u_long(unsigned long nb, int base);
char			*ft_itoa_base_u_long_maj(unsigned long nb, int base);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putendl(const char *str);
void			ft_putnbr(long nb);
void			ft_putshort(short nb);
void			ft_putsigned_char(signed char nb);
void			ft_putlong(long nb);
void			ft_putlong_long(long long nb);
void			ft_putintmax_t(intmax_t nb);
void			ft_putssize_t(ssize_t nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
int				ft_putnbr_octal(unsigned long nb);
int				ft_putlong_x_up(unsigned long nb);
int				ft_putnbr_x_up(unsigned int nb);
void			ft_putascii(char nb);
void			ft_put_unsigned_ascii(unsigned char nb);
int				ft_putlong_long_x_up(unsigned long long nb);
int				ft_putlong_long_x_low(unsigned long long nb);
int				ft_putlong_x_low(unsigned long nb);
void			ft_putunsigned_long(unsigned long nb);
void			ft_putunsigned_long_long(unsigned long long nb);
void			ft_putsize_t(size_t nb);
t_liste			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_liste **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_liste **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_liste **alst, t_liste *new);
void			ft_lstiter(t_liste *lst, void (*f)(t_liste *elem));
t_liste			*ft_lstmap(t_liste *lst, t_liste *(*f)(t_liste *elemi));
void			*ft_memdup(const void *src);
int				bin_to_deci(char *nbr);
int				ft_len_nb(unsigned int nb, int base);
int				ft_putlong_x_low_wp(unsigned long nb);
int				ft_putnbr_x_up_wp(unsigned int nb);
int				get_next_line(int const fd, char **line);
#endif
