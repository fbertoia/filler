/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:42:15 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:42:28 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nb)
{
	int		i;
	int		sign;
	char	*res;

	if (nb == 0 || nb == -2147483648)
		return (ft_excep_itoa(nb));
	sign = 0;
	if (nb < 0)
		sign = 1;
	if (nb < 0)
		nb *= -1;
	i = 0;
	while (ft_recur_power(10, i) <= nb)
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
