/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:41:08 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 10:38:18 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_numlen(long long nb)
{
	int				res;

	res = 1;
	while (nb > 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

static char			*ft_convert(char *s, long long n, int len)
{
	int				i;
	long long		nb;
	int				tmp;

	nb = n;
	i = len - 2;
	tmp = -1;
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
		tmp = 0;
	}
	s[len - 1] = '\0';
	while (i > tmp)
	{
		s[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (s);
}

static long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char				*ft_itoa(int n)
{
	char			*res;
	int				len;
	long long		nb;

	nb = (long long)n;
	res = NULL;
	len = 0;
	len += ft_numlen(ft_abs(nb));
	if (n < 0)
		len++;
	else if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	return (ft_convert(res, nb, len));
}
