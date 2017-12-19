/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:51:56 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:52:00 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (size == 0 || !(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (size-- > 0)
		str[size] = 0;
	return ((void*)str);
}
