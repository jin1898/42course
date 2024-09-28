/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:03:42 by hyseong           #+#    #+#             */
/*   Updated: 2022/11/23 19:04:56 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntword(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			word++;
		s++;
	}
	return (word);
}

static char	**ft_free(char **split, int j)
{
	while (j-- > 0)
		free(split[j]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	char	*tmp;

	split = malloc(sizeof(char *) * (ft_cntword(s, c) + 1));
	if (!split || !s)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			tmp = (char *)s;
			while (*s && *s != c)
				s++;
			split[i] = ft_substr(tmp, 0, s - tmp);
			if (!split[i++])
				return (ft_free(split, i - 1));
		}
	}
	split[i] = 0;
	return (split);
}
