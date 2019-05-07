/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:26:22 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 22:22:11 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_calc	*prepare(int y, t_prg *p)
{
	t_calc		*c;

	c = (t_calc *)malloc(sizeof(t_calc));
	c->y = y;
	c->p = p;
	return (c);
}

static void		setpx(int *px, int x, int y, t_vec col)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	px[x + y * WIN_W] = vec_tocolor(col);
}

static t_ray	set_ray(int x, int y, t_cam c)
{
	t_ray		ray;
	t_vec		tmp;

	tmp = vec_mul_fact(c.ri, x * X_I);
	tmp = vec_sub_vec(tmp, vec_mul_fact(c.up, y * Y_I));
	ray.o = c.pos;
	ray.dir = vec_norm(vec_sub_vec(vec_add_vec(c.corner, tmp), c.pos));
	ray.t = -1.0f;
	return (ray);
}

void			*compute(void *a)
{
	t_calc		*c;
	int			x;
	t_ray		ray;

	c = (t_calc *)a;
	x = 0;
	while (x < WIN_W)
	{
		ray = set_ray(x, c->y, c->p->cam);
		setpx(c->p->area, x, c->y, raytracer(c->p->scene, ray));
		x++;
	}
	free(c);
	return (NULL);
}

void			render(t_prg *p)
{
	pthread_t	tc[WIN_H];
	int			y;

	y = 0;
	while (y < WIN_H)
	{
		pthread_create(&tc[y], NULL, compute, prepare(y, p));
		y++;
	}
	y = 0;
	while (y < WIN_H)
	{
		pthread_join(tc[y], NULL);
		y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
