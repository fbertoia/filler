/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:06:13 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:06:15 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (dst[i])
		i++;
	while (src[++j])
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst);
}
