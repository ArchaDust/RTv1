/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 21:25:10 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 16:26:23 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"

# define BUFF_SIZE 4096

/*
**		Struct: gnl
**
**		Contains:
**	data: the actual string that is being processed.
**	fd: the current fd for that data.
**	chk: keep track of read() return value.
**	next: obviously, a pointer to the next element.
*/

typedef struct		s_gnl
{
	char			*data;
	int				fd;
	int				chk;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
