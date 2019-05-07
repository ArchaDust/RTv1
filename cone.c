/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cone.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 18:27:58 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 18:58:19 by aberneli    ###    #+. /#+    ###.fr     */
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

static t_vec	gnormal(t_vec o, t_elem *cne)
{
	double		angle;
	double		t;
	t_vec		v1;
	t_vec		v2;

	angle = cne->range;
	t = vec_dist(o, cne->vec1) / cos(angle);
	if (isnan(t))
		return (getb());
	v1 = vec_add_vec(cne->vec1, vec_mul_fact(cne->vec2, -t));
	v2 = vec_add_vec(cne->vec1, vec_mul_fact(cne->vec2, t));
	if (vec_dist(v1, o) >= vec_dist(v2, o))
		v1 = v2;
	v1 = vec_sub_vec(o, v1);
	return (v1);
}

static double	calc_b(t_ray r, t_elem *c)
{
	t_vec		t1;
	t_vec		t2;
	t_vec		dp;
	double		t;
	double		b;

	dp = vec_sub_vec(r.o, c->vec1);
	t1 = vec_mul_fact(c->vec2, dot_product(r.dir, c->vec2));
	t1 = vec_sub_vec(r.dir, t1);
	t2 = vec_mul_fact(c->vec2, dot_product(dp, c->vec2));
	t2 = vec_sub_vec(dp, t2);
	b = 2 * p2(cos(c->range)) * dot_product(t1, t2);
	t = 2 * p2(sin(c->range)) * dot_product(r.dir, c->vec2);
	t *= dot_product(dp, c->vec2);
	b -= t;
	return (b);
}

static double	calc_c(t_ray r, t_elem *cne)
{
	t_vec		dp;
	t_vec		t;
	double		c;

	dp = vec_sub_vec(r.o, cne->vec1);
	t = vec_mul_fact(cne->vec2, dot_product(dp, cne->vec2));
	t = vec_sub_vec(dp, t);
	c = p2(cos(cne->range)) * dot_product(t, t);
	c -= p2(sin(cne->range)) * p2(dot_product(dp, cne->vec2));
	return (c);
}

double			rt_cone(t_ray r, t_elem *c, t_inter *inter)
{
	t_vec		t;
	double		a;
	double		b;
	double		delta;

	t = vec_mul_fact(c->vec2, dot_product(r.dir, c->vec2));
	t = vec_sub_vec(r.dir, t);
	a = p2(cos(c->range)) * dot_product(t, t);
	a -= p2(sin(c->range)) * p2(dot_product(r.dir, c->vec2));
	b = calc_b(r, c);
	delta = b * b - 4 * calc_c(r, c) * a;
	if (delta < 0.0f)
		return (-1.0f);
	r.t = calc_d(a, b, delta);
	if (r.t < 0.0f || r.t > 100000.0f)
		return (-1.0f);
	set_inter1(inter, c, calc_ray(r).o);
	set_inter2(inter, r.t, gnormal(calc_ray(r).o, c));
	return (r.t);
}
