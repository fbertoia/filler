/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:04:30 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:04:32 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsigned_char(signed char nb)
{
	if (nb == -128)
	{
		ft_putchar('-');
		ft_putchar('1');
		ft_putsigned_char(28);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	if (nb / 10 > 0)
		ft_putsigned_char(nb / 10);
	ft_putchar(nb % 10 + '0');
}
