/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 21:27:59 by aberneli     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 00:12:33 by aberneli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**		Function: gnlnew
**
**		Use:
**	This function is called whenever get_next_line() needs to increase its
**	internal memory (if there if no corresponding fd stored, or if no fd have
**	been processed yet).
*/

static t_gnl		*gnlnew(const int fd)
{
	t_gnl			*gnl;

	gnl = (t_gnl *)malloc(sizeof(t_gnl));
	gnl->data = ft_strnew(1);
	gnl->chk = 1;
	gnl->fd = fd;
	gnl->next = NULL;
	return (gnl);
}

/*
**		Function: gnlfind
**
**		Use:
**	This function is called when get_next_line needs to work with the t_gnl
**	corresponding to said fd. If the fd is not found anywhere, we will called
**	gnlnew().
*/

static t_gnl		*gnlfind(t_gnl *gnl, const int fd)
{
	t_gnl			*act;

	while (gnl)
	{
		if (gnl->fd == fd)
			break ;
		if (!gnl->next)
		{
			act = gnlnew(fd);
			gnl->next = act;
			return (act);
		}
		gnl = gnl->next;
	}
	return (gnl);
}

/*
**		Function: gnlnl
**
**		Use:
**	This function will parse the known data of argument "gnl" to cut the string
**	until a '\n'. that will be stored in "*line" so the get_next_line user will
**	receive the requested line.
*/

static int			gnlnl(t_gnl **gnl, char **line)
{
	char			*t1;
	char			*t2;

	if ((t1 = ft_strchr((*gnl)->data, '\n')) != NULL)
	{
		*t1 = '\0';
		*line = ft_strdup((*gnl)->data);
		t2 = (*gnl)->data;
		(*gnl)->data = ft_strdup(t1 + 1);
		ft_strdel(&t2);
		return (1);
	}
	return (0);
}

/*
**		Function: gnlrd
**
**		Use:
**	This function will read the file and call gnlnl() to be able to sent there
**	processed string into "line"
*/

static int			gnlrd(t_gnl **act, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*t;

	while (((*act)->chk = read((*act)->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[(*act)->chk] = '\0';
		t = ft_strjoin((*act)->data, buf);
		ft_strdel(&(*act)->data);
		(*act)->data = t;
		if (gnlnl(act, line) == 1)
			return (1);
	}
	return (0);
}

/*
**		Function: get_next_line
**
**		Use:
**	Self explanatory, this function will retrive one line at a time of a said
**	file, returning values corresponding to errors checks (-1 is an error, 0 is
**	the end of file and 1 means that there is still lines to gather from file).
*/

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*act;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!gnl)
		gnl = gnlnew(fd);
	act = gnlfind(gnl, fd);
	if (gnlrd(&act, line) == 1)
		return (1);
	if (act->chk == -1)
		return (-1);
	if (ft_strlen(act->data) == 0)
		return (0);
	if (gnlnl(&act, line) == 1)
		return (1);
	else
	{
		*line = ft_strdup(act->data);
		ft_strclr(act->data);
	}
	return (1);
}
