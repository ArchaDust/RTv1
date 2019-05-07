/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 05:54:23 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 22:51:05 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

double			p2(double d)
{
	return (d * d);
}

double			min(double a, double b)
{
	if (a > 0 && a <= b)
		return (a);
	if (b > 0 && b < a)
		return (b);
	return (a);
}

double			delta(double a, double b, double c)
{
	return (b * b - 4.0f * a * c);
}

double			vec_dist(t_vec o, t_vec p)
{
	return (sqrt(p2(o.x - p.x) + p2(o.y - p.y) + p2(o.z - p.z)));
}
