/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 07:59:36 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 05:46:40 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_elem	*get_cam(t_elem *lst)
{
	while (lst)
	{
		if (lst->type == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static t_elem	*clean_cam(t_elem *lst)
{
	t_elem		*t;
	t_elem		*t2;
	int			i;

	i = 0;
	t = lst;
	while (t)
	{
		if (t->type == 1)
		{
			check_warn(i);
			i = 1;
			t2 = t->next;
			if (!(lst = del_attach(lst, t)))
				return (NULL);
			t = t2;
		}
		else
			t = t->next;
	}
	return (lst);
}

static int		init_cam(t_cam *cam, t_elem *e)
{
	if (!e)
		return (-1);
	cam->pos = e->vec1;
	cam->orient = vec_sub_vec(e->vec2, e->vec1);
	cam->orient = vec_norm(cam->orient);
	viewplane_init(cam);
	return (0);
}

int				init(t_prg *p, char *arg)
{
	int			fd;

	if ((fd = open(arg, 0)) < 0)
		return (-1);
	if (!(p->scene = scene_load(fd)))
	{
		close(fd);
		return (-2);
	}
	close(fd);
	if (init_cam(&p->cam, get_cam(p->scene)) == -1)
		return (-3);
	p->scene = clean_cam(p->scene);
	return (1);
}

int				ginit(t_prg *p)
{
	int			i[3];

	if (!(p->mlx = mlx_init()))
		return (-1);
	if (!(p->win = mlx_new_window(p->mlx, WIN_W, WIN_H, "RTV1")))
		return (-2);
	if (!(p->img = mlx_new_image(p->mlx, WIN_W, WIN_H)))
		return (-3);
	p->area = (int *)mlx_get_data_addr(p->img, &i[0], &i[1], &i[2]);
	mlx_hook(p->win, 17, (1L << 17), &quit_hook, NULL);
	mlx_key_hook(p->win, key_hook, p);
	return (1);
}
