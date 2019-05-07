/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:22:56 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 06:40:03 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		d_len;
	size_t		i;

	i = 0;
	d_len = 0;
	while (s1[d_len])
		d_len++;
	while (i < n && s2[i])
	{
		s1[d_len] = s2[i];
		d_len++;
		i++;
	}
	s1[d_len] = '\0';
	return (s1);
}
