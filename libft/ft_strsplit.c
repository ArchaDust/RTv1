/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:08:56 by aberneli          #+#    #+#             */
/*   Updated: 2017/11/16 10:41:43 by aberneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_words(char const *s, char c)
{
	size_t		i;
	int			words;
	int			n_word;

	i = 0;
	words = 0;
	n_word = 1;
	while (s[i])
	{
		if (n_word && s[i] != c)
		{
			words++;
			n_word = 0;
		}
		if (s[i] == c)
			n_word = 1;
		i++;
	}
	return (words);
}

static char		*get_next_word(char const *s, char c, size_t *beg)
{
	size_t		len;

	while (s[*beg] == c)
		*beg += 1;
	len = *beg;
	while (s[*beg])
	{
		if (s[*beg] == c)
			return (ft_strsub(s, len, *beg - len));
		*beg += 1;
	}
	return (ft_strsub(s, len, *beg - len));
}

char			**ft_strsplit(char const *s, char c)
{
	int			words;
	char		**splits;
	size_t		i;
	size_t		beg;

	if (!s)
		return (NULL);
	words = get_words(s, c);
	splits = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splits)
		return (NULL);
	i = 0;
	beg = 0;
	while (words--)
	{
		splits[i] = get_next_word(s, c, &beg);
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
