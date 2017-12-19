/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:52:37 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:52:39 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char*)s1;
	tmp_s2 = (unsigned char*)s2;
	i = 0;
	while (++i <= len)
		if (tmp_s1[i - 1] != tmp_s2[i - 1])
			return (tmp_s1[i - 1] - tmp_s2[i - 1]);
	return (0);
}
