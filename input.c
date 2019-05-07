/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 09:05:45 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 14:47:46 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

int		quit_hook(int code, void *a)
{
	a = NULL;
	code = 0;
	exit(0);
	return (0);
}

int		key_hook(int keycode, void *a)
{
	t_prg	*p;

	p = (t_prg *)a;
	if (keycode == 53)
		exit(0);
	return (0);
}
