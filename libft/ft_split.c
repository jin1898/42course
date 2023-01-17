/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:10:23 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2022/11/29 12:16:19 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_alfree(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

static size_t	ft_wdct(char const *s, char c)
{
	size_t	listsize;
	size_t	index;

	index = 0;
	listsize = 0;
	while (s[index] != '\0')
	{
		if ((index == 0 && s[index] != c) || \
		(s[index] == c && s[index + 1] != '\0' && s[index + 1] != c))
			listsize++;
		index++;
	}
	return (listsize);
}

char	**ft_split(char const *s, char c)
{
	char	**news;
	size_t	index;
	size_t	findc;
	size_t	nextk;

	index = 0;
	findc = 0;
	news = (char **)malloc(sizeof(char *) * (ft_wdct(s, c) + 1));
	if (!news)
		return (NULL);
	while (index < ft_wdct(s, c) && s[findc] != '\0')
	{
		while (s[findc] == c)
			findc++;
		nextk = findc;
		while (s[findc] != c && s[findc] != '\0')
			findc++;
		news[index] = ft_substr(s, nextk, findc - nextk);
		if (news[index++] == 0)
			return (ft_alfree(news));
	}
	news[index] = NULL;
	return (news);
}
