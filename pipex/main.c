/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsunwoo <jsunwoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:59:49 by jsunwoo           #+#    #+#             */
/*   Updated: 2023/04/24 20:44:34 by jsunwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_db	db;

	what_parameter(argv, argc, &db);
	find_path(envp, &db);
	if (!find_path)
		return (0);
	// connect_infile_outfile();
	// make_pipe_and_open();
	// make_child();
	// close_pipe();
	// waitpid();
	// free_everything();
}

void	what_parameter(char **argv, int argc, t_db *db)
{
	if (ft_strcmp(argv[1], "here_doc") == 0 && argv[1] != 0)
	{
		db->h_flag = 1;
		if (argc < 6)
			error_message("Invalid number of arguments. \n");
	}
	else
	{
		db->h_flag = 0;
		if (argc < 5)
			error_message("Invalid number of arguments. \n");
	}
}

void	error_message(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	while (*s1_c != '\0' && *s2_c != '\0')
	{
		if (*s1_c != *s2_c)
			return (*s1_c - *s2_c);
		s1_c++;
		s2_c++;
	}
	return (0);
}
