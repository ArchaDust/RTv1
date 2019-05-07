/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   viewplane.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:31:06 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 08:55:43 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_vec			cross_product(t_vec v1, t_vec v2)
{
	t_vec		res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

void			uv(t_cam *c)
{
	c->up = cross_product(c->ri, c->orient);
}

void			rv(t_cam *c)
{
	c->ri = cross_product(c->up, c->orient);
}

void			viewplane_init(t_cam *c)
{
	t_vec		t;
	t_vec		npos;

	t = c->orient;
	c->up.x = 0.0f;
	c->up.y = -1.0f;
	c->up.z = 0.0f;
	rv(c);
	uv(c);
	npos = vec_add_vec(vec_mul_fact(t, VP_D), vec_mul_fact(c->up, VPH2));
	t = vec_mul_fact(c->ri, VPW2);
	c->corner = vec_add_vec(c->pos, vec_sub_vec(npos, t));
}
