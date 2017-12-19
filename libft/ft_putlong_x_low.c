/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_x_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:20:22 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/25 09:34:22 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_putlong_x_low(unsigned long nb)
{
	int		res;

	res = 1;
	if (nb / 16 > 0)
		res += ft_putlong_x_low(nb / 16);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
		ft_putchar(nb % 16 + 'a' - 10);
	return (res);
}
