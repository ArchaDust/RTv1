/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sphere.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:25:06 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:58:43 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static double	dosomecalc(t_ray ray, t_vec c)
{
	double		res;

	res = ray.dir.x * (ray.o.x - c.x);
	res += ray.dir.y * (ray.o.y - c.y);
	res += ray.dir.z * (ray.o.z - c.z);
	return (res);
}

static double	doothercalc(t_vec o, t_vec c)
{
	double		res;

	res = (p2(o.x - c.x) + p2(o.y - c.y) + p2(o.z - c.z));
	return (res);
}

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

double			rt_sphere(t_ray ray, t_elem *sph, t_inter *inter)
{
	double		a;
	double		b;
	double		c;
	double		delta;
	t_vec		normal;

	a = p2(ray.dir.x) + p2(ray.dir.y) + p2(ray.dir.z);
	b = dosomecalc(ray, sph->vec1) * 2.0f;
	c = doothercalc(ray.o, sph->vec1) - p2(sph->range);
	delta = b * b - 4 * c * a;
	if (delta < 0.0f)
	{
		wrong_inter(inter);
		return (-1.0f);
	}
	ray.t = calc_d(a, b, delta);
	if (ray.t < 0.0f || ray.t > 100000.0f)
		return (-1.0f);
	set_inter1(inter, sph, calc_ray(ray).o);
	normal = vec_sub_vec(calc_ray(ray).o, sph->vec1);
	set_inter2(inter, ray.t, normal);
	return (ray.t);
}
