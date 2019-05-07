/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:37:25 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 10:40:42 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*res;

	res = NULL;
	res = (char *)malloc(ft_strlen(s1) + 1);
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, s1);
	return (res);
}
