/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 15:18:07 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 00:47:15 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void		start(char *file)
{
	t_prg	prg;
	int		chk;

	chk = init(&prg, file);
	if (chk == -1)
		puterr("File couldn't open or does not exist. Quitting...");
	else if (chk == -2)
		puterr("Scene file is somewhat invalid. Quitting...");
	else if (chk == -3)
		puterr("No camera defined. Quitting...");
	if (chk < 0)
		return ;
	chk = ginit(&prg);
	if (chk == -1)
		puterr("mlx_init() failed. Quitting...");
	else if (chk == -2)
		puterr("mlx_new_window() failed. Quitting...");
	else if (chk == -3)
		puterr("mlx_new_image() failed. Quitting...");
	if (chk < 0)
		return ;
	render(&prg);
	mlx_loop(prg.mlx);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
		return (usage());
	start(argv[1]);
	return (0);
}
