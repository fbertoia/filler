/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:46:58 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/02 11:12:35 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_octal(unsigned long nb)
{
	int		res;

	res = 1;
	if (nb / 8 > 0)
		res += ft_putnbr_octal(nb / 8);
	ft_putchar(nb % 8 + '0');
	return (res);
}
