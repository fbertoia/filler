/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_long_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:05:32 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:05:33 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsigned_long_long(unsigned long long nb)
{
	if (nb / 10 > 0)
		ft_putunsigned_long_long(nb / 10);
	ft_putchar(nb % 10 + '0');
}
