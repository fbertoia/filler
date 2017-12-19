/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u_long_maj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 13:05:27 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/10 13:06:34 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_nb_u_long_maj(unsigned long nb, int base)
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

char	*ft_itoa_base_u_long_maj(unsigned long nb, int base)
{
	int		len;
	char	*res;

	if (base == 10)
		return (ft_itoa_base_u_long_maj(nb, base));
	if (nb == 0)
		return ("0");
	len = ft_len_nb_u_long_maj(nb, base);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = 0;
	while (len-- > 0)
	{
		if (nb % base < 10)
			res[len] = nb % base + '0';
		else
			res[len] = nb % base + 'A' - 10;
		nb /= base;
	}
	return (res);
}
