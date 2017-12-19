/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:53:40 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:53:42 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src)
{
	unsigned char	*dest;
	unsigned char	*tmp;
	int				len;

	if (!src)
		return (0);
	tmp = (unsigned char*)src;
	len = ft_strlen((const char*)tmp);
	if (!(dest = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1))))
		return (dest);
	return (ft_memcpy((void*)dest, (void*)src, len));
}
