/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:05:23 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:05:25 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsigned_long(unsigned long nb)
{
	if (nb / 10 > 0)
		ft_putunsigned_long(nb / 10);
	ft_putchar(nb % 10 + '0');
}
