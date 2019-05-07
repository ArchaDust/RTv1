/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_manage.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 03:35:33 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 04:15:13 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_elem		*del_attach(t_elem *beg, t_elem *del)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	if (beg == del)
	{
		tmp = beg->next;
		free(del);
		return (tmp);
	}
	tmp = beg;
	while (tmp->next != del && tmp)
		tmp = tmp->next;
	if (!tmp)
		return (beg);
	tmp2 = tmp->next->next;
	free(tmp->next);
	tmp->next = tmp2;
	return (beg);
}
