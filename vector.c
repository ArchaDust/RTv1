/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:53:02 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 15:14:41 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		vec_mul_fact(t_vec v, double fact)
{
	v.x *= fact;
	v.y *= fact;
	v.z *= fact;
	return (v);
}

t_vec		vec_add_vec(t_vec v1, t_vec v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec		vec_sub_vec(t_vec v1, t_vec v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec		vec_norm(t_vec v)
{
	double	norm;

	norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x /= norm;
	v.y /= norm;
	v.z /= norm;
	return (v);
}

int			vec_tocolor(t_vec v)
{
	int		res;

	res = (int)(v.x * 255) * R + (int)(v.y * 255) * G + (int)(v.z * 255);
	return (res);
}
