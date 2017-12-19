/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:52:27 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:52:29 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int n, size_t len)
{
	size_t			i;
	unsigned char	c;
	unsigned char	*tmp;

	c = (unsigned char)n;
	tmp = (unsigned char*)s;
	i = 0;
	while (i < len)
		if (tmp[i++] == c)
			return (tmp + i - 1);
	return (NULL);
}
