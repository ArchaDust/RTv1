/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:20:31 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/10 11:07:38 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strbytes(char *s)
{
	int		res;

	res = 0;
	while (*s++)
		res++;
	return (res);
}

void		ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	int		i;
	int		len;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	len = ft_strbytes(s);
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
