/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 07:23:53 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:46:01 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_vec			getb(void)
{
	t_vec		c;

	c.x = 0;
	c.y = 0;
	c.z = 0;
	return (c);
}

t_vec			vec_mul_vec(t_vec v1, t_vec v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec			get_colorfact(double dist, double range, t_vec color)
{
	if (dist > range || range <= 0.0f)
		return (getb());
	return (vec_mul_fact(color, 1.0f - (dist / range)));
}

double			dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
