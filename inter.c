/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inter.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 11:54:48 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 15:52:14 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_inter		reset_inter(void)
{
	t_inter	res;

	res.inter.x = 0.0f;
	res.inter.y = 0.0f;
	res.inter.z = 0.0f;
	res.normal.x = 0.0f;
	res.normal.y = 0.0f;
	res.normal.z = 0.0f;
	res.node = NULL;
	res.dist = -1.0f;
	res.cross = 0;
	return (res);
}

void		set_inter1(t_inter *inter, t_elem *elem, t_vec ipos)
{
	inter->node = elem;
	inter->inter = ipos;
	inter->cross = 1;
}

void		set_inter2(t_inter *inter, float dist, t_vec normal)
{
	inter->dist = dist;
	inter->normal = normal;
}

void		wrong_inter(t_inter *res)
{
	res->inter.x = 0.0f;
	res->inter.y = 0.0f;
	res->inter.z = 0.0f;
	res->normal.x = 0.0f;
	res->normal.y = 0.0f;
	res->normal.z = 0.0f;
	res->node = NULL;
	res->dist = -1.0f;
	res->cross = 0;
}

t_inter		check_inter(t_inter a, t_inter b)
{
	if (a.cross == 0 && b.cross == 1)
		return (b);
	if (a.cross == 1 && b.cross == 1)
		if (b.dist > 0.001f && b.dist < 100000.0f && b.dist < a.dist)
			return (b);
	return (a);
}
