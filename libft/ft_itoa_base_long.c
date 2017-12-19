/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:42:55 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 13:09:34 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_nb_long(long long nb, int base)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb = nb / base;
		++i;
	}
	if (i == 0)
		return (1);
	return (i);
}

char	*ft_itoa_base_long(long long nb, int base)
{
	int		len;
	char	*res;

	if (base == 10)
		return (ft_itoa_long(nb));
	if (nb == 0)
		return ("0");
	len = ft_len_nb_long(nb, base);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = 0;
	while (len-- > 0)
	{
		if (nb % base < 10)
			res[len] = nb % base + '0';
		else
			res[len] = nb % base + 'a' - 10;
		nb /= base;
	}
	return (res);
}
