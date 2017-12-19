/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:07:07 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 12:07:08 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i] || !s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
