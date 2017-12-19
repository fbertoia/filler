/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur_power.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:05:59 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:06:01 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_recur_power(int nb, int pow)
{
	if (nb == 1)
		return (1);
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	if (nb == 0)
		return (0);
	return (nb * ft_recur_power(nb, pow - 1));
}
