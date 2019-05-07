/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loader_routines_1.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 23:53:24 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 13:13:36 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_elem			**move_to_last(t_elem **lst)
{
	if (*lst == NULL)
		return (lst);
	while ((*lst)->next)
		lst = &((*lst)->next);
	return (lst);
}

int				load_camera(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 1))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 1;
	t->range = 0.0L;
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	vec_norm(t->vec1);
	t->vec2 = parse_vec(split[2]);
	t->vec3 = getb();
	return (0);
}

int				load_spot(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 2))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 2;
	t->range = (double)ft_atoi(split[2]);
	if (t->range < 0.01f)
		t->range = 1.0f;
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	t->vec2 = getb();
	t->vec3 = parse_vec(split[3]);
	t->vec3.x /= 255.0f;
	t->vec3.y /= 255.0f;
	t->vec3.z /= 255.0f;
	return (0);
}

int				load_sphere(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 3))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 3;
	t->range = (double)ft_atoi(split[2]);
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	t->vec2 = getb();
	t->vec3 = parse_vec(split[3]);
	t->vec3.x /= 255.0f;
	t->vec3.y /= 255.0f;
	t->vec3.z /= 255.0f;
	return (0);
}

int				load_plane(t_elem **lst, char **split)
{
	t_elem		*t;

	if (!check_spl(split, 4))
		return (1);
	if (!(t = (t_elem *)malloc(sizeof(t_elem))))
		return (2);
	if (*lst == NULL)
		*lst = t;
	else
		(*lst)->next = t;
	t->type = 4;
	t->range = 0.0f;
	t->next = NULL;
	t->vec1 = parse_vec(split[1]);
	t->vec2 = parse_vec(split[2]);
	t->vec3 = parse_vec(split[3]);
	t->vec2 = vec_norm(t->vec2);
	t->vec3.x /= 255.0f;
	t->vec3.y /= 255.0f;
	t->vec3.z /= 255.0f;
	return (0);
}
