/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:39:59 by clianne           #+#    #+#             */
/*   Updated: 2019/11/20 16:28:12 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		cw(const char *s, char c)
{
	int		q_words;
	int		in_word;

	in_word = 0;
	q_words = 0;
	while (*s != '\0')
	{
		if (in_word == 1 && *s == c)
			in_word = 0;
		if (in_word == 0 && *s != c)
		{
			in_word = 1;
			q_words++;
		}
		s++;
	}
	return (q_words);
}

static int		gwl(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static	void	freelist(char **words)
{
	int	index;

	if (!(*words))
		return ;
	index = 0;
	while (words[index])
	{
		free(words[index]);
		words[index] = NULL;
		index++;
	}
	free(words);
	words = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**wds;
	int		q_words;
	int		index;

	if (!s || !c)
		return (NULL);
	index = 0;
	q_words = cw((const char *)s, c);
	if (!(wds = (char **)malloc(sizeof(*wds) * (cw((const char *)s, c) + 1))))
		return (NULL);
	while (q_words-- > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		wds[index] = ft_strsub((const char *)s, 0, gwl((const char *)s, c));
		if (!wds[index])
		{
			freelist(wds);
			return (NULL);
		}
		s = s + gwl(s, c);
		index++;
	}
	wds[index] = NULL;
	return (wds);
}
