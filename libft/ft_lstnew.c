/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:51:46 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/30 13:11:27 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstnew(const void *content, size_t content_size)
{
	t_liste	*list;

	if (!(list = (t_liste*)malloc(sizeof(t_liste))))
		return (NULL);
	list->content = ft_memdup(content);
	list->content_size = content_size;
	if (!content)
		list->content_size = 0;
	list->next = NULL;
	return (list);
}
