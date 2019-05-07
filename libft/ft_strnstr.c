/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:46:59 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/13 17:37:25 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;

	if (*need == '\0')
		return ((char *)hay);
	i = ft_strlen(need);
	while (*hay != '\0' && len-- >= i)
	{
		if (*hay == *need && ft_memcmp(hay, need, i) == 0)
			return ((char *)hay);
		hay++;
	}
	return (NULL);
}
