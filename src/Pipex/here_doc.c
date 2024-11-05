/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:27:47 by gdel-val          #+#    #+#             */
/*   Updated: 2024/08/18 23:27:58 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	here_doc(char **argv, int *fd)
{
	char	*here;
	char 	*delimitier;

	delimitier = ft_strjoin(argv[2], "\n");
	while (1)
	{
		ft_putstr_fd(">", 0);
		here = get_next_line(0);
		if (ft_strncmp(here, delimitier, ft_strlen(here)) == 0)
		{
			free(delimitier);
			break ;
		}
		ft_putstr_fd(here, fd[WRITE]);
		free(here);
	}
	free(here);
	close(fd[WRITE]);
}

void	dup_here(char **argv)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error(PIPE, NULL);
	here_doc(argv, fd);
	if (dup2(fd[READ], STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
}