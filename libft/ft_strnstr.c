/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:09:49 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:09:51 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (to_find[0] == 0)
		return ((char*)str);
	while (str[j] != '\0' && j < len)
	{
		if (to_find[0] == str[j])
		{
			i = 1;
			while (to_find[i] == str[j + i] && to_find[i] != '\0')
				i++;
			if (i + j > len)
				return (0);
			if (to_find[i] == '\0')
				return ((char*)str + j);
		}
		j++;
	}
	return (0);
}
