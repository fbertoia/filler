/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_long_x_low.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:49:47 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/25 09:31:55 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_putlong_long_x_low(unsigned long long nb)
{
	int		res;

	res = 1;
	if (nb / 16 > 0)
		res += ft_putlong_long_x_low(nb / 16);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
		ft_putchar(nb % 16 + 'a' - 10);
	return (res);
}
