/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:52:10 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:52:13 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int n, size_t len)
{
	unsigned char	c;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	c = (unsigned char)n;
	while (len-- && *tmp_src != c)
		*(tmp_dst++) = *(tmp_src++);
	if (*tmp_src != c)
		return (NULL);
	*(tmp_dst++) = *(tmp_src++);
	return ((void*)tmp_dst);
}
