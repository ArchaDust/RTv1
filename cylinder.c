/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cylinder.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 18:27:58 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:58:33 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static double	calc_d(double a, double b, double delta)
{
	double		res[2];

	if (delta != 0)
	{
		delta = (double)sqrt(delta);
		res[0] = (-b + delta) / (a * 2);
		res[1] = (-b - delta) / (a * 2);
		if (res[0] < res[1])
			res[1] = res[0];
		return (res[1]);
	}
	return (-b / (a * 2));
}

static double	dlen(t_vec res)
{
	return (p2(res.x) + p2(res.y) + p2(res.z));
}

static t_vec	calc_cyl_normal(t_vec o, t_elem *cyl)
{
	t_vec		res;
	t_vec		tmp;
	double		t;

	res = vec_sub_vec(o, cyl->vec1);
	t = dlen(res);
	t = sqrt(t - p2(cyl->range));
	if (isnan(t))
		return (vec_sub_vec(o, cyl->vec1));
	res = vec_add_vec(cyl->vec1, vec_mul_fact(cyl->vec2, t));
	tmp = vec_add_vec(cyl->vec1, vec_mul_fact(cyl->vec2, -t));
	if (vec_dist(res, o) >= vec_dist(tmp, o))
		res = tmp;
	res = vec_sub_vec(o, res);
	return (res);
}

double			rt_cylinder(t_ray ray, t_elem *cyl, t_inter *inter)
{
	double	v[3];
	double	delta;
	t_vec	normal;
	t_vec	pc[3];

	pc[0] = cross_product(ray.dir, cyl->vec2);
	pc[1] = cross_product(ray.o, cyl->vec2);
	pc[2] = cross_product(cyl->vec1, cyl->vec2);
	v[0] = dot_product(pc[0], pc[0]);
	v[1] = 2 * (dot_product(pc[0], pc[1]) - dot_product(pc[0], pc[2]));
	v[2] = dot_product(pc[2], pc[2]) + dot_product(pc[1], pc[1]);
	v[2] = v[2] - 2 * dot_product(pc[1], pc[2]) - p2(cyl->range);
	delta = v[1] * v[1] - 4 * v[2] * v[0];
	if (delta < 0.0f)
		return (-1.0f);
	ray.t = calc_d(v[0], v[1], delta);
	if (ray.t < 0.0f || ray.t > 100000.0f)
		return (-1.0f);
	set_inter1(inter, cyl, calc_ray(ray).o);
	normal = calc_cyl_normal(calc_ray(ray).o, cyl);
	set_inter2(inter, ray.t, normal);
	return (ray.t);
}
