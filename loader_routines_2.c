/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader_routines_2.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 18:31:32 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 21:48:35 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec	convcol(t_vec v)
{
	v.x /= 255.0f;
	v.y /= 255.0f;
	v.z /= 255.0f;
	if (v.x > 1.0f)
		v.x = 1.0f;
	if (v.y > 1.0f)
		v.y = 1.0f;
	if (v.z > 1.0f)
		v.z = 1.0f;
	return (v);
}

int				load_cylinder(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 5))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 5;
	t->range = ft_atoi(split[3]);
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	t->vec2 = parse_vec(split[2]);
	t->vec2 = vec_norm(t->vec2);
	t->vec3 = parse_vec(split[4]);
	t->vec3 = convcol(t->vec3);
	return (0);
}

int				load_cone(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 6))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 6;
	t->range = ft_atoi(split[3]);
	if (t->range > 179)
		t->range = 179;
	if (t->range < 1)
		t->range = 1;
	t->range = t->range * (M_PI / 180.0f);
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	t->vec2 = parse_vec(split[2]);
	t->vec2 = vec_norm(t->vec2);
	t->vec3 = parse_vec(split[4]);
	t->vec3 = convcol(t->vec3);
	return (0);
}
