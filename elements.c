/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   elements.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 13:23:13 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:45:51 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

int			clr_spl(char **spl, int err)
{
	int		i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (err);
}

int			addelem(t_elem **lst, char **split)
{
	int		res;
	int		chk;

	if (!split || !split[0])
		return (1);
	chk = 0;
	res = check_keywords(split[0]);
	if (res < 1 || res > 6)
		return (clr_spl(split, 1));
	if (res == 1)
		chk = load_camera(move_to_last(lst), split);
	else if (res == 2)
		chk = load_spot(move_to_last(lst), split);
	else if (res == 3)
		chk = load_sphere(move_to_last(lst), split);
	else if (res == 4)
		chk = load_plane(move_to_last(lst), split);
	else if (res == 5)
		chk = load_cylinder(move_to_last(lst), split);
	else if (res == 6)
		chk = load_cone(move_to_last(lst), split);
	return (clr_spl(split, chk));
}

void		*cleanelem(t_elem *lst)
{
	t_elem	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (NULL);
}
