/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:09:10 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:09:12 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, int n)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (dst[i])
		i++;
	while (src[++j] && j < n)
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst);
}
