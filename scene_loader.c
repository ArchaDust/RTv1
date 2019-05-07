/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scene_loader.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 11:17:29 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 17:31:16 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_strmerge(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	putwarn(s);
	free(s);
}

t_vec		parse_vec(char *s)
{
	char	**spl;
	t_vec	v;

	spl = NULL;
	if (s)
		spl = ft_strsplit(s, ',');
	if (spl && spl[0] && spl[1] && spl[2])
	{
		v.x = (double)ft_atoi(spl[0]);
		v.y = (double)ft_atoi(spl[1]);
		v.z = (double)ft_atoi(spl[2]);
	}
	else
	{
		v.x = 0.0f;
		v.y = 0.0f;
		v.z = 0.0f;
	}
	clr_spl(spl, 0);
	return (v);
}

int			check_spl(char **spl, int type)
{
	if (type == 1 && spl[1] && spl[2])
		return (1);
	if (type == 2 && spl[1] && spl[2] && spl[3])
		return (1);
	if (type == 3 && spl[1] && spl[2] && spl[3])
		return (1);
	if (type == 4 && spl[1] && spl[2] && spl[3])
		return (1);
	if (type == 5 && spl[1] && spl[2] && spl[3] && spl[4])
		return (1);
	if (type == 6 && spl[1] && spl[2] && spl[3] && spl[4])
		return (1);
	return (0);
}

int			check_keywords(char *s)
{
	if (!ft_strcmp(s, "CAMERA"))
		return (1);
	if (!ft_strcmp(s, "SPOT"))
		return (2);
	if (!ft_strcmp(s, "SPHERE"))
		return (3);
	if (!ft_strcmp(s, "PLANE"))
		return (4);
	if (!ft_strcmp(s, "CYLINDER"))
		return (5);
	if (!ft_strcmp(s, "CONE"))
		return (6);
	return (0);
}

t_elem		*scene_load(int fd)
{
	int		step;
	int		err;
	char	*l;
	t_elem	*lst;

	err = 0;
	step = 1;
	lst = NULL;
	while (get_next_line(fd, &l) > 0)
	{
		if (*l == '\0')
			err = 1;
		else
			err = addelem(&lst, ft_strsplit(l, ' '));
		free(l);
		if (err == 1)
			ft_strmerge(ft_strdup("Invalid argument line "), ft_itoa(step));
		else if (err == 2)
			return (cleanelem(lst));
		step++;
	}
	return (lst);
}
