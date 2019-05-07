/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:49:08 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/09 11:34:22 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*conv;
	size_t			i;

	conv = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (conv[i] == (unsigned char)c)
			return ((void *)(conv + i));
		i++;
	}
	return (NULL);
}
