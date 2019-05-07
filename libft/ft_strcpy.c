/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:48:39 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/09 10:01:13 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src) + 1;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
