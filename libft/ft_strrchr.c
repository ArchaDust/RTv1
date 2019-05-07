/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:26:38 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/09 09:53:47 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s) + 1;
	i = 0;
	res = NULL;
	while (i < len)
	{
		if (*s == c)
			res = (char *)s;
		s++;
		i++;
	}
	return (res);
}
