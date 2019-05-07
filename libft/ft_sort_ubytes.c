/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:41 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/15 17:57:41 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_bytescmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	long long		r1;
	long long		r2;
	size_t			i[2];

	r1 = 0;
	r2 = 0;
	i[0] = 0;
	i[1] = 1;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i[0] < n)
	{
		r1 += c1[i[0]] * i[1];
		r2 += c2[i[0]] * i[1];
		i[0]++;
		i[1] *= 256;
	}
	return ((unsigned long long)r1 - (unsigned long long)r2);
}

static void			ft_sorting(void *b, size_t t_len, int off)
{
	if (ft_bytescmp(b + off, b + off + t_len, t_len) > 0)
		ft_swap_bytes(b + off, b + off + t_len, t_len);
}

static void			ft_setvalues(int *v, int a_len, size_t t_len)
{
	v[0] = 0;
	v[1] = 0;
	v[2] = a_len * t_len;
	v[3] = t_len;
}

static void			ft_shakersort(void *bytes, int arraylen, size_t typelen)
{
	int				vars[4];

	ft_setvalues(vars, arraylen, typelen);
	while (vars[1] < vars[2])
	{
		ft_sorting(bytes, typelen, vars[0]);
		vars[0] += vars[3];
		if (vars[0] >= vars[2])
		{
			vars[3] = -vars[3];
			vars[2] -= typelen;
			vars[0] = vars[2];
		}
		if (vars[0] < vars[1])
		{
			vars[3] = -vars[3];
			vars[1] += typelen;
			vars[0] = vars[1];
		}
	}
}

void				ft_sort_ubytes(void *bytes, int arraylen, size_t typelen)
{
	if (!typelen)
		return ;
	if (arraylen < 2)
		return ;
	else if (arraylen == 2)
	{
		ft_sorting(bytes, typelen, 0);
		return ;
	}
	ft_shakersort(bytes, arraylen, typelen);
}
