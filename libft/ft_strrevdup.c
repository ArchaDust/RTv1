/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:28:18 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 02:23:34 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrevdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = NULL;
	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[len - i - 1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
