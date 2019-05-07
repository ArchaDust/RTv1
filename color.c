/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:59:18 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 16:22:50 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec	limitv(t_vec res)
{
	if (res.x > 1.0f)
		res.x = 1.0f;
	if (res.y > 1.0f)
		res.y = 1.0f;
	if (res.z > 1.0f)
		res.z = 1.0f;
	if (res.x < 0.0f)
		res.x = 0.0f;
	if (res.y < 0.0f)
		res.y = 0.0f;
	if (res.z < 0.0f)
		res.z = 0.0f;
	return (res);
}

t_vec			apply_light(t_inter inter, t_elem *l, t_vec res, t_vec p)
{
	t_vec		add;
	t_vec		light;
	double		angle;

	light = vec_norm(vec_sub_vec(l->vec1, inter.inter));
	angle = dot_product(vec_norm(inter.normal), light);
	if (angle <= 0.0f)
		return (res);
	add = vec_mul_fact(vec_mul_vec(inter.node->vec3, l->vec3), angle);
	p = getb();
	res = vec_add_vec(res, vec_add_vec(add, p));
	return (limitv(res));
}
