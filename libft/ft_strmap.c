/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:37:32 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 10:41:12 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	char	*res;
	int		i;
	int		len;

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
		res[i] = (*f)(s[i]);
		i++;
	}
	return (res);
}
