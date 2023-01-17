/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwoo-jin <sunwoo-jin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:47:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2022/11/29 21:20:02 by sunwoo-jin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*boxtable;
	size_t		i;
	size_t		s_strlen;

	i = 0;
	s_strlen = ft_strlen(s);
	if (!s || !f)
		return (0);
	boxtable = malloc(sizeof(char) * (s_strlen + 1));
	if (boxtable == NULL)
		return (NULL);
	while (i < s_strlen)
	{
		boxtable[i] = f(i, s[i]);
		i++;
	}
	boxtable[i] = '\0';
	return (boxtable);
}
