/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:45:33 by atgerard          #+#    #+#             */
/*   Updated: 2017/10/30 13:10:19 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_liste	*ft_lstmap(t_liste *lst, t_liste *(*f)(t_liste *elem))
{
	t_liste	*link;
	t_liste	*next_link;
	t_liste	*first_link;

	if (!lst)
		return (NULL);
	link = (*f)(lst);
	first_link = link;
	lst = lst->next;
	while (lst)
	{
		next_link = (*f)(lst);
		lst = lst->next;
		link->next = next_link;
		link = next_link;
	}
	return (first_link);
}
