/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 18:16:34 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 12:55:13 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void		pick_rt(t_ray ray, t_elem *scn, t_inter *inter)
{
	if (scn->type == 3)
		rt_sphere(ray, scn, inter);
	if (scn->type == 4)
		rt_plane(ray, scn, inter);
	if (scn->type == 5)
		rt_cylinder(ray, scn, inter);
	if (scn->type == 6)
		rt_cone(ray, scn, inter);
}

t_ray			calc_ray(t_ray ray)
{
	ray.o = vec_add_vec(ray.o, vec_mul_fact(ray.dir, ray.t));
	ray.dir.x = 0.0f;
	ray.dir.y = 0.0f;
	ray.dir.z = 0.0f;
	ray.t = -1.0f;
	return (ray);
}

static int		lightcheck(t_elem *beg, t_inter inter, t_ray ray)
{
	t_inter		res;
	t_inter		curr;

	res = reset_inter();
	while (beg)
	{
		curr = reset_inter();
		pick_rt(ray, beg, &curr);
		res = check_inter(res, curr);
		beg = beg->next;
	}
	if (res.node == NULL || res.node != inter.node)
		return (0);
	return (1);
}

t_vec			lightray(t_elem *beg, t_elem *e, t_inter inter, t_vec p)
{
	t_elem		*l;
	t_vec		res;
	t_ray		ray;
	int			chk;

	res = getb();
	l = beg;
	chk = 0;
	while (l)
	{
		if (l->type == 2)
		{
			chk = 1;
			ray.dir = vec_norm(vec_sub_vec(inter.inter, l->vec1));
			ray.o = l->vec1;
			if (lightcheck(beg, inter, ray))
				res = apply_light(inter, l, res, p);
		}
		l = l->next;
	}
	if (!chk)
		return (e->vec3);
	return (res);
}

t_vec			raytracer(t_elem *beg, t_ray ray)
{
	t_inter		res;
	t_inter		curr;
	t_elem		*t;

	res = reset_inter();
	t = beg;
	while (t)
	{
		curr = reset_inter();
		pick_rt(ray, t, &curr);
		res = check_inter(res, curr);
		t = t->next;
	}
	if (res.cross == 0)
		return (getb());
	return (lightray(beg, res.node, res, ray.o));
}
