/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_up_wp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:43:59 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/25 09:31:10 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int		ft_putnbr_x_up_wp(unsigned int nb)
{
	int		res;

	res = 1;
	if (nb / 16 > 0)
		res += ft_putnbr_x_up_wp(nb / 16);
	return (res);
}
