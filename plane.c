/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   plane.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 06:20:21 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/03 16:22:12 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void	fill(double dv, t_vec normal, double t, t_inter *inter)
{
	if (dv >= 0)
	{
		normal.x = -normal.x;
		normal.y = -normal.y;
		normal.z = -normal.z;
	}
	set_inter2(inter, t, normal);
}

double		rt_plane(t_ray ray, t_elem *pln, t_inter *inter)
{
	double	dv;
	double	t;

	dv = dot_product(pln->vec2, ray.dir);
	if (dv == 0)
	{
		wrong_inter(inter);
		return (-1.0f);
	}
	t = -(dot_product(pln->vec2, vec_sub_vec(ray.o, pln->vec1)) / dv);
	if (t < 0.001f || t > 100000.0f)
	{
		wrong_inter(inter);
		return (-1.0f);
	}
	ray.t = t;
	ray = calc_ray(ray);
	set_inter1(inter, pln, ray.o);
	fill(dv, pln->vec2, t, inter);
	return (t);
}
