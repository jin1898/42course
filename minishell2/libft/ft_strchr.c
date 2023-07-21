/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:33:44 by hyseong           #+#    #+#             */
/*   Updated: 2022/11/22 18:33:45 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*stmp;
	char	ctmp;
	int		i;

	i = 0;
	if (!s)
		return (0);
	stmp = (char *)s;
	ctmp = (char)c;
	while (stmp[i] != ctmp)
	{
		if (stmp[i] == '\0')
			return (0);
		i++;
	}
	return (&stmp[i]);
}
