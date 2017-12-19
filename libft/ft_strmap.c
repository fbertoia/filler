/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:08:53 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:08:55 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		i;
	char	*res;

	if (!str || !(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	i = -1;
	while (str[++i])
		res[i] = (*f)(str[i]);
	res[i] = 0;
	return (res);
}
