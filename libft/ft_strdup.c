/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:07:42 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:07:44 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (dest);
	return (ft_strcpy(dest, src));
}
