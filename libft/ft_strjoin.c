/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:13:30 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/10 11:11:16 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	res = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	res = (char *)malloc(len1 + len2 + 1);
	if (res == NULL)
		return (NULL);
	while (i < len1 + len2 + 1)
	{
		if (i < len1)
			res[i] = s1[i];
		else
			res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
