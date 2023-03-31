/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Text_editing_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:08:23 by sunwoo-jin        #+#    #+#             */
/*   Updated: 2023/03/31 17:24:44 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_mod_strdup(char *s)
{
	char	*new_p;
	int		size;
	int		i;

	new_p = 0;
	size = ft_strlen(s);
	i = 0;
	new_p = malloc(size + 1);
	if (!(new_p))
		return (new_p);
	while (s[i] && s[i] != '\n')
	{
		new_p[i] = s[i];
		i++;
	}
	new_p[i] = '\0';
	return (new_p);
}

char	*ft_mode_strjoin(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	new_mem = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_mod_strdup(s2));
	else if (s2 == 0)
		return (ft_mod_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (0);
	ft_strlcpy(new_mem, s1, s1_len + 1);
	ft_strlcpy(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}
