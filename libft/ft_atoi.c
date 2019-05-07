/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:26:48 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/09 11:03:12 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_testspc(char c, int t)
{
	if (t)
	{
		if (c == 32 || c == 9 || c == '\n' || c == 13 || c == '\f' || c == 11)
			return (1);
	}
	else if (!t)
		if (c != 32 && c != 9 && c != '\n' && c != 13 && c != '\f' && c != 11)
			return (1);
	return (0);
}

static int	ft_discardspaces(const char *str)
{
	int		i;

	i = 0;
	if (*str != '+' && *str != '-' && (!ft_isdigit(*str)))
		if (ft_testspc(*str, 0) == 1)
			return (-1);
	while (ft_testspc(str[i], 1) == 1)
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		neg;

	res = 0;
	neg = 1;
	i = ft_discardspaces(str);
	if (i == -1)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * neg);
}
