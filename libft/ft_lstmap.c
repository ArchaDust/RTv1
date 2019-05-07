/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:00:27 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/15 20:45:07 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n;
	t_list	*tmp;
	t_list	*beg;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = (*f)(lst);
	n = ft_lstnew(tmp->content, tmp->content_size);
	if (n == NULL)
		return (NULL);
	beg = n;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		n->next = ft_lstnew(tmp->content, tmp->content_size);
		if (n->next == NULL)
			return (NULL);
		n = n->next;
		lst = lst->next;
	}
	return (beg);
}
