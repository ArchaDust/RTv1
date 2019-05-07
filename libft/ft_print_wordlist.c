/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wordlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:24:24 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/15 11:46:26 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_wordlist(const char **words, int fd)
{
	int		i;

	i = 0;
	while (words[i])
	{
		ft_putendl_fd(words[i], fd);
		i++;
	}
}
