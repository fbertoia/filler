/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_ascii.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 10:04:40 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/10 10:05:19 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_unsigned_ascii(unsigned char nb)
{
	if (nb / 10 > 0)
		ft_put_unsigned_ascii(nb / 10);
	ft_putchar(nb % 10 + '0');
}
