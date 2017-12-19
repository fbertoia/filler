/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putshort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:04:19 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:04:21 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putshort(short nb)
{
	if (nb == -32768)
	{
		ft_putchar('-');
		ft_putchar('3');
		ft_putshort(2768);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	if (nb / 10 > 0)
		ft_putshort(nb / 10);
	ft_putchar(nb % 10 + '0');
}
