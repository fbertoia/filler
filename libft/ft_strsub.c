/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:10:34 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:10:35 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*res;

	if (!str || !(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	res = ft_strncpy(res, str + start, len);
	res[len] = 0;
	return (res);
}
