/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:51:20 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 10:41:18 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	if (s == NULL || f == NULL)
		return (NULL);
	res = NULL;
	i = 0;
	len = ft_strlen(s);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
