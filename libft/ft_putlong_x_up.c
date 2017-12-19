/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_x_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 09:16:54 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/25 09:28:30 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_putlong_x_up(unsigned long nb)
{
	int		res;

	res = 1;
	if (nb / 16 > 0)
		res += ft_putlong_x_up(nb / 16);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + '0');
	else
		ft_putchar(nb % 16 + 'A' - 10);
	return (res);
}
