/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 15:15:09 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 12:41:59 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include <mlx.h>
# include <pthread.h>

# define WIN_W 1600
# define WIN_H 900

# define VP_W 1.0F
# define VP_H 0.5625F
# define VP_D 1.0F

# define VPH2 (VP_H / 2.0F)
# define VPW2 (VP_W / 2.0F)

# define X_I (VP_W / WIN_W)
# define Y_I (VP_H / WIN_H)

# define R 65536
# define G 256

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_elem
{
	unsigned char	type;
	double			range;
	t_vec			vec1;
	t_vec			vec2;
	t_vec			vec3;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_cam
{
	t_vec			pos;
	t_vec			orient;
	t_vec			up;
	t_vec			ri;
	t_vec			corner;
}					t_cam;

typedef struct		s_prg
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*area;
	t_cam			cam;
	t_elem			*scene;
}					t_prg;

typedef struct		s_calc
{
	int				y;
	t_prg			*p;
}					t_calc;

typedef struct		s_ray
{
	t_vec			o;
	t_vec			dir;
	double			t;
}					t_ray;

typedef struct		s_inter
{
	t_vec			inter;
	t_vec			normal;
	t_elem			*node;
	double			dist;
	int				cross;
}					t_inter;

/*
**	init.c
*/

int					init(t_prg *p, char *arg);
int					ginit(t_prg *p);

/*
** viewplane.c
*/

t_vec				cross_product(t_vec v1, t_vec v2);
void				uv(t_cam *c);
void				rv(t_cam *c);
void				viewplane_init(t_cam *c);

/*
**	render.c
*/

void				*compute(void *a);
void				render(t_prg *p);

/*
**	calc.c
*/

double				p2(double d);
double				delta(double a, double b, double c);
double				min(double a, double b);
double				vec_dist(t_vec o, t_vec p);

/*
**	ray.c
*/

t_ray				calc_ray(t_ray ray);
t_vec				lightray(t_elem *beg, t_elem *e, t_inter inter, t_vec p);
t_vec				raytracer(t_elem *beg, t_ray ray);

/*
**	color.c
*/

t_vec				apply_light(t_inter i, t_elem *l, t_vec res, t_vec p);

/*
**	inter.c
*/

t_inter				reset_inter(void);
void				set_inter1(t_inter *inter, t_elem *elemm, t_vec ipos);
void				set_inter2(t_inter *inter, float dist, t_vec normal);
void				wrong_inter(t_inter *res);
t_inter				check_inter(t_inter a, t_inter b);

/*
**	sphere.c
*/

double				rt_sphere(t_ray ray, t_elem *sph, t_inter *inter);

/*
**	plane.c
*/

double				rt_plane(t_ray ray, t_elem *pln, t_inter *inter);

/*
**	cylinder.c
*/

double				rt_cylinder(t_ray ray, t_elem *cyl, t_inter *inter);

/*
**	cone.c
*/

double				rt_cone(t_ray ray, t_elem *cyl, t_inter *inter);

/*
**	vector.c
*/

t_vec				vec_mul_fact(t_vec v, double fact);
t_vec				vec_add_vec(t_vec v1, t_vec v2);
t_vec				vec_sub_vec(t_vec v1, t_vec v2);
t_vec				vec_norm(t_vec v);
int					vec_tocolor(t_vec v);

/*
**	scene_loader.c
*/

t_vec				parse_vec(char *s);
int					check_spl(char **spl, int type);
int					check_keywords(char *s);
t_elem				*scene_load(int fd);

/*
**	elements.c
*/

int					clr_spl(char **spl, int err);
int					addelem(t_elem **lst, char **split);
void				*cleanelem(t_elem *lst);

/*
**	loader_routines_1.c
*/

t_elem				**move_to_last(t_elem **lst);
int					load_camera(t_elem **lst, char **split);
int					load_spot(t_elem **lst, char **split);
int					load_sphere(t_elem **lst, char **split);
int					load_plane(t_elem **lst, char **split);

/*
**	loader_routines_2.c
*/

int					load_cylinder(t_elem **lst, char **split);
int					load_cone(t_elem **lst, char **split);

/*
**	input.c
*/

int					quit_hook(int code, void *a);
int					key_hook(int keycode, void *a);

/*
**	list_manage.c
*/

t_elem				*del_attach(t_elem *beg, t_elem *del);

/*
**	tools.c
*/

t_vec				getb(void);
t_vec				vec_mul_vec(t_vec v1, t_vec v2);
t_vec				get_colorfact(double dist, double range, t_vec color);
double				dot_product(t_vec a, t_vec b);

/*
**	console.c
*/

int					usage(void);
int					puterr(char *s);
int					putwarn(char *s);
void				check_warn(int i);

#endif
