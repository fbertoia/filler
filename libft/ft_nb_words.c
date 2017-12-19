/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:54:30 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/23 11:54:32 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_words(const char *str, char c)
{
	int		i;
	int		words;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			++words;
			while (str[i] && str[i] != c)
				++i;
		}
		while (str[i] == c)
			++i;
	}
	return (words);
}
