/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:53:53 by atgerard          #+#    #+#             */
/*   Updated: 2017/11/08 10:01:41 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	i = 0;
	while (i++ < len)
		if (dst + i == src)
		{
			i = 0;
			while (i++ < len)
				tmp_dst[i - 1] = tmp_src[i - 1];
			return ((void*)tmp_dst);
		}
	while (len-- > 0)
		tmp_dst[len] = tmp_src[len];
	return ((void*)tmp_dst);
}
