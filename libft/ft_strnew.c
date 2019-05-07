/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:59:08 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 16:11:14 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	s[i] = '\0';
	return (s);
}
