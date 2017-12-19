/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putssize_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:04:50 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:04:52 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putssize_t(ssize_t nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putssize_t(147483648);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	if (nb / 10 > 0)
		ft_putssize_t(nb / 10);
	ft_putchar(nb % 10 + '0');
}
