/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:44:06 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:44:09 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_long(long long nb)
{
	int		i;
	int		sign;
	char	*res;

	sign = 0;
	if (nb < 0)
		sign = 1;
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (ft_recur_power_long(10, i) <= nb)
		++i;
	if (!(res = (char*)malloc(sizeof(char) * (i + sign + 1))))
		return (0);
	res[i + sign] = 0;
	while (i-- > 0)
	{
		res[i + sign] = nb % 10 + '0';
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
