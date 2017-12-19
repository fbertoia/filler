/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:44:50 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/30 13:09:07 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_liste **alst, void (*del)(void*, size_t))
{
	t_liste	*link;

	if (!alst)
		return ;
	link = *alst;
	(*del)(link->content, link->content_size);
	free(*alst);
	*alst = NULL;
}
