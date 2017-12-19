/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:10:26 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:10:28 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	j = 0;
	if (to_find[0] == 0)
		return ((char*)str);
	while (str[j] != '\0')
	{
		if (to_find[0] == str[j])
		{
			i = 1;
			while (to_find[i] == str[j + i] && to_find[i] != '\0')
				i++;
			if (to_find[i] == '\0')
				return ((char*)str + j);
		}
		j++;
	}
	return (0);
}
