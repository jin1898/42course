/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:14:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/24 19:10:11 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>

typedef struct s_databox
{
	int		h_flag;
	char	*path;
}	t_db;

int	ft_strcmp(char *s1, char *s2);

#endif
