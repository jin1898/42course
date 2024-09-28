/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseong <hyseong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:14:16 by hyseong           #+#    #+#             */
/*   Updated: 2022/11/22 20:14:18 by hyseong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	all;

	all = count * size;
	tmp = malloc(all);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, all);
	return (tmp);
}
