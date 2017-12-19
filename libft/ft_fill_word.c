/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:40:59 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:41:01 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_word(char *dest, const char *src, int length)
{
	int		i;

	i = -1;
	while (++i < length)
		dest[i] = src[i];
	dest[i] = '\0';
}
