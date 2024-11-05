/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:27:47 by gdel-val          #+#    #+#             */
/*   Updated: 2024/04/23 19:27:58 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void free_arguments_bonus(t_arguments_bonus *args)
{
	int	i;
	int	j;

	i = -1;
	if (args->commands != NULL)
	{
		while (args->commands[++i] != NULL)
			free(args->commands[i]);
		free(args->commands);
	}
	i = -1;
	if (args->splits != NULL)
	{
		while (args->splits[++i] != NULL)
		{
			j = -1;
			while (args->splits[i][++j] != NULL)
				free(args->splits[i][j]);
			free(args->splits[i]);
		}
		free(args->splits);
	}
}

void	pipex_free(int **fds, pid_t *pid, int i, int x)
{
	while (i > 0)
		free(fds[--i]);
	free(fds);
	if (pid)
		free(pid);
	if (x == 0)
		ft_error(MALLOC, NULL);
	if (x == 1)
		ft_error(PIPE, NULL);
	if (x == 2)
		ft_error(FORK, NULL);
	else
		exit(0);
}

void	fds_free(int **fds, int i, int x)
{
	while (i > 0)
		free(fds[--i]);
	free(fds);
	if (x == 0)
		ft_error(MALLOC, NULL);
	if (x == 1)
		ft_error(PIPE, NULL);
	exit(0);
}

int	**piping(t_arguments_bonus arguments, int argn)
{
	int	i;
	int	**fds;

	fds = ft_calloc(argn - 3 - arguments.here_doc - 1, sizeof(int*));
	if (!fds)
		ft_error(MALLOC, NULL);
	i = -1;
	while (++i < argn - 3 - arguments.here_doc - 1)
	{
		fds[i] = ft_calloc(2, sizeof(int));
		if (!fds[i])
			fds_free(fds, i, 0);
		if (pipe(fds[i]) == -1)
			fds_free(fds, i, 1);
	}
	return (fds);
}

void ft_wait(t_arguments_bonus arguments, int argn, pid_t *pid, int **fds)
{
	int	i;

	i = -1;
	while (++i < argn - 3 - arguments.here_doc - 1)
	{
		close(fds[i][READ]);
		close(fds[i][WRITE]);
	}
	i = -1;
	while (++i < argn - 3 - arguments.here_doc)
	{
		if (waitpid(pid[i], NULL, 0) == -1)
			ft_error(WAIT, NULL);
	}
}