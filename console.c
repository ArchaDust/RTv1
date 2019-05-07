/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   console.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 12:50:56 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 03:51:20 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

int			usage(void)
{
	ft_putendl_fd("usage: rtv1 scene_file", 1);
	return (0);
}

int			puterr(char *s)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(s, 2);
	return (1);
}

int			putwarn(char *s)
{
	ft_putstr_fd("Warning: ", 1);
	ft_putendl_fd(s, 1);
	return (1);
}

void		check_warn(int i)
{
	if (i == 1)
		putwarn("What is up with that much CAMERA bro?");
}
