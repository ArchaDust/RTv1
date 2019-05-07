/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:36:09 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/15 11:24:07 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen(long long n)
{
	int		res;

	res = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		res++;
	}
	return (res);
}