/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:09:02 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:09:03 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!str || !(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	i = 0;
	while (str[i++])
		res[i - 1] = (*f)(i - 1, str[i - 1]);
	res[i - 1] = 0;
	return (res);
}
