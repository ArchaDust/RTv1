/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:00:11 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/15 19:54:02 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_swap_bytes(void *b1, void *b2, size_t typelen)
{
	unsigned char	*c1;
	unsigned char	*c2;
	unsigned char	swap;
	size_t			i;

	if (!b1 || !b2 || !typelen)
		return ;
	i = 0;
	c1 = (unsigned char *)b1;
	c2 = (unsigned char *)b2;
	while (i < typelen)
	{
		swap = c1[i];
		c1[i] = c2[i];
		c2[i] = swap;
		i++;
	}
}
