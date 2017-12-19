/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <atgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:29:40 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/16 13:01:09 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		no_conv(int *str, int index, const char *format);
void	ft_putlong(long nb);
int		aff_wchar_t(char *bin, int bn);
char	*one_byte(char *bin, int len);
char	*two_byte(char *bin, int len);
char	*three_byte(char *bin, int len);
char	*four_byte(char *bin, int len);
int		pfudor(unsigned int arg, int *str);
int		pfudor2(int len, char *ret, char *bin);
int		print_c_up(va_list ap, int *str);
int		print_c_low(va_list ap, int *str);
int		print_s_low(va_list ap, int *str);
int		print_s_up(va_list ap, int *str);
int		print_p_low(va_list ap, int *str, int len);
int		print_i_low(va_list ap, int *str);
int		print_i_low_intmax(va_list ap, int *str);
int		print_i_low_bis(int *str, int arg, int len, int bn);
int		print_i_low_ter(int *str, int arg, int len, int bn);
int		print_i_low_short(va_list ap, int *str);
int		print_i_low_bis_short(int *str, short arg, int len, int bn);
int		print_i_low_ter_short(int *str, short arg, int len, int bn);
int		print_i_low_short_bis(int *str, short arg, int len, int bn);
int		print_i_low_short_ter(int *str, short arg, int len, int bn);
int		print_i_low_long(va_list ap, int *str);
int		print_i_low_long_bis(int *str, long arg, int len, int bn);
int		print_i_low_long_ter(int *str, long arg, int len, int bn);
int		print_i_low_l_l(va_list ap, int *str);
int		print_i_low_l_l_bis(int *str, long long arg, int len, int bn);
int		print_i_low_l_l_ter(int *str, long long arg, int len, int bn);
int		print_i_low_h_h(va_list ap, int *str);
int		print_i_low_h_h_bis(int *str, char arg, int len, int bn);
int		print_i_low_h_h_ter(int *str, char arg, int len, int bn);
int		print_d_low_long_long(va_list ap, int *str);
int		print_d_low_long_long_bis(int *str, long long arg, int len, int bn);
int		print_d_low_long_long_ter(int *str, long long arg, int len, int bn);
int		print_d_low_long(va_list ap, int *str);
int		print_d_low_long_bis(int *str, long arg, int len, int bn);
int		print_d_low_long_ter(int *str, long arg, int len, int bn);
int		print_d_low_short(va_list ap, int *str);
int		print_d_low_short_bis(int *str, short arg, int len, int bn);
int		print_d_low_short_ter(int *str, short arg, int len, int bn);
int		print_d_low_signed_char(va_list ap, int *str);
int		print_d_low_signed_char_bis(int *str, signed char arg, int len, int bn);
int		print_d_low_signed_char_ter(int *str, signed char arg, int len, int bn);
int		print_d_low_intmax_t(va_list ap, int *str);
int		print_d_low_intmax_t_bis(int *str, intmax_t arg, int len, int bn);
int		print_d_low_intmax_t_ter(int *str, intmax_t arg, int len, int bn);
int		print_d_low_ssize_t(va_list ap, int *str);
int		print_d_low_ssize_t_bis(int *str, ssize_t arg, int len, int bn);
int		print_d_low_ssize_t_ter(int *str, ssize_t arg, int len, int bn);
int		print_d_low(va_list ap, int *str);
int		print_d_low_bis(int *str, int arg, int len, int bn);
int		print_d_low_ter(int *str, int arg, int len, int bn);
int		preci_d_low(int *str, int arg);
int		parser_d(va_list ap, int *str);
int		print_d_up(va_list ap, int *str);
int		print_d_up_bis(int *str, long arg, int len, int bn);
int		print_d_up_ter(int *str, long arg, int len, int bn);
int		print_u_low(va_list ap, int *str);
int		print_u_low_bis(int *str, unsigned int arg, int len, int bn);
int		print_u_low_ter(int *str, unsigned int arg, int len, int bn);
int		print_u_low_h_h(va_list ap, int *str);
int		print_u_low_bis_h_h(int *str, unsigned char arg, int len, int bn);
int		print_u_low_ter_h_h(int *str, unsigned char arg, int len, int bn);
int		parser_u(va_list ap, int *str);
int		print_u_low_intmax_t(va_list ap, int *str);
int		print_u_low_long(va_list ap, int *str);
int		print_u_low_long_long(va_list ap, int *str);
int		print_u_low_size_t(va_list ap, int *str);
int		print_u_up(va_list ap, int *str);
int		print_u_low_short(va_list ap, int *str);
int		print_u_low_short_bis(int *str, unsigned short arg, int len, int bn);
int		print_u_low_short_ter(int *str, unsigned short arg, int len, int bn);
int		print_x_low(va_list ap, int *str);
int		print_x_low_ter(int *str, unsigned int arg, int len, int bn);
int		print_x_low_bis(int *str, int len, int bn);
int		print_x_low_h_h(va_list ap, int *str);
int		print_x_low_ter_h_h(int *str, unsigned char arg, int len, int bn);
int		print_x_low_bis_h_h(int *str, int len, int bn);
int		print_x_low_long(va_list ap, int *str);
int		print_x_low_bis_long(int *str, int len, int bn);
int		print_x_low_ter_long(int *str, unsigned long long arg, int len, int bn);
int		print_x_low_long_long(va_list ap, int *str);
int		print_x_low_l_l_bis(int *str, int len, int bn);
int		print_x_low_l_l_ter(int *str, unsigned long long arg, int len, int bn);
int		print_x_up(va_list ap, int *str);
int		print_x_up_bis(int *str, unsigned int arg, int len, int bn);
int		print_x_up_ter(int *str, unsigned int arg, int len, int bn);
int		print_x_up_u_t(va_list ap, int *str);
int		print_x_up_bis_u_t(int *str, int len, int bn);
int		print_x_up_ter_u_t(int *str, uintmax_t arg, int len, int bn);
int		print_x_up_h_h(va_list ap, int *str);
int		print_x_up_bis_h_h(int *str, int len, int bn);
int		print_x_up_ter_h_h(int *str, unsigned char arg, int len, int bn);
int		print_x_up_long(va_list ap, int *str);
int		print_x_up_bis_long(int *str, int len, int bn);
int		print_x_up_bis_ter(int *str, unsigned long long arg, int len, int bn);
int		print_x_low_unitmax(va_list ap, int *str);
int		print_x_low_bis_unitmax(int *str, int len, int bn);
int		print_x_low_ter_unitmax(int *str, uintmax_t arg, int len, int bn);
int		print_o_low(va_list ap, int *str);
int		print_o_low_bis(int *str, int len, int bn);
int		print_o_low_ter(int *str, unsigned int arg, int bn);
int		print_o_low_four(int *str, unsigned int arg, int bn, int ret);
int		print_o_low_uintmax_t(va_list ap, int *str);
int		print_o_low_bis_u_t(int *str, int len, int bn);
int		print_o_low_ter_u_t(int *str, unsigned long arg, int bn);
int		print_o_low_h_h(va_list ap, int *str);
int		print_o_low_bis_h_h(int *str, int len, int bn);
int		print_o_low_ter_h_h(int *str, unsigned char arg, int bn);
int		print_o_low_short(va_list ap, int *str);
int		print_o_low_bis_short(int *str, int len, int bn);
int		print_o_low_ter_short(int *str, unsigned int arg, int bn);
int		print_o_up(va_list ap, int *str);
int		print_o_up_bis(int *str, int len, int bn);
int		print_o_up_ter(int *str, unsigned long arg, int len, int bn);
int		print_modulo(int *str);
int		print_modulo_two(int size, int res);
int		check_conv_bis(const char *format, va_list ap, int *i, int *str);
int		check_conv(const char *format, va_list ap, int *i, int *str);
void	first_flags(const char *format, int *i, int *str);
void	find_numb(const char *format, int *i, int *str, int n);
int		check_flag(const char *format, va_list ap, int *i, int *str);
int		write_z(int *str, int bn, char *ret);
int		write_m(int *str, int bn, char *ret, char *diese);
int		write_min(int *str, int bn);
int		write_min_short(int *str, int bn);
int		write_min_char_signed(int *str, int bn);
int		write_space(int *str, int bn, int arg);
int		write_space_s(int *str, int len, int bn);
int		write_preci(int *str, int bn, char *ret);

#endif
