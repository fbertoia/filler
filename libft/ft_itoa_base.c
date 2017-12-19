/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:42:36 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:42:38 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_nb(unsigned int nb, int base)
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

char	*ft_itoa_base(unsigned int nb, int base)
{
	int		len;
	char	*res;

	if (base == 10)
		return (ft_itoa(nb));
	if (nb == 0)
		return (ft_strdup("0"));
	len = ft_len_nb(nb, base);
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
