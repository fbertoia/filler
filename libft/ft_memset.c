/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:54:15 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:54:17 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *tab, int n, size_t len)
{
	unsigned char	c;
	unsigned char	*tmp;

	c = (unsigned char)n;
	tmp = (unsigned char*)tab;
	while (len-- > 0)
		tmp[len] = c;
	tab = (void*)tmp;
	return (tab);
}
