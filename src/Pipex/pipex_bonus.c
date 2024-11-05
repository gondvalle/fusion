/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:37:45 by gdel-val          #+#    #+#             */
/*   Updated: 2024/04/17 20:37:51 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	child_first(t_arguments_bonus arguments, int *fds, char **env)
{
	if (ft_strncmp(arguments.argv[1] , "here_doc", 8) != 0)
	{
		if (dup2(arguments.in_fd, STDIN_FILENO) == -1)
			ft_error(DUP, NULL);
		close(arguments.in_fd);
	}
	close(fds[READ]);
	if (dup2(fds[WRITE], STDOUT_FILENO) == -1)
		ft_error(DUP, NULL);
	close(fds[WRITE]);
	if (execve(arguments.commands[0], arguments.splits[0], env) == -1)
		ft_error(COMMAND, arguments.argv[2 + arguments.here_doc]);
}

void	child_last(t_arguments_bonus arguments, int **fds, char **env, int argn)
{
	int	last;
	int	i;

	last = argn - 3 - arguments.here_doc - 2;
	i = -1;
	while (++i < last)
	{
		close(fds[i][READ]);
		close(fds[i][WRITE]);
	}
	close(fds[last][WRITE]);
	if (dup2(fds[last][READ], STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
	close(fds[last][READ]);
	if (dup2(arguments.out_fd, STDOUT_FILENO) == -1)
		ft_error(DUP, NULL);
	close(arguments.out_fd);
	if (execve(arguments.commands[last + 1], arguments.splits[last + 1], env) == -1)
		ft_error(COMMAND, arguments.argv[last + 3]);
}

void	exec_commands(t_arguments_bonus arguments, int **fds, char **env, int i)
{
	int	j;

	j = -1;
	while (++j < i - 1)
	{
		close(fds[j][READ]);
		close(fds[j][WRITE]);
	}
	close(fds[i][READ]);
	close(fds[i - 1][WRITE]);
	if (dup2(fds[i - 1][READ], STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
	close(fds[i - 1][READ]);
	if (dup2(fds[i][WRITE], STDOUT_FILENO) == -1)
		ft_error(DUP, NULL);
	close(fds[i][WRITE]);
	if (execve(arguments.commands[i], arguments.splits[i], env) == -1)
		ft_error(COMMAND, arguments.argv[i + 2]);
}

void	pipex(t_arguments_bonus arguments, int argn, int **fds, char **env)
{
	int		i;
	pid_t	*pid;

	pid = ft_calloc(argn - 3 - arguments.here_doc, sizeof(pid_t));
	if (!pid)
		pipex_free(fds, pid, argn - 3 - arguments.here_doc - 1, 0);
	i = -1;
	while (++i < argn - 3 - arguments.here_doc)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			pipex_free(fds, pid, argn - 3 - arguments.here_doc - 1, 2);
		if (pid[i] == 0)
		{
			if (i == 0)
				child_first(arguments, fds[0], env);
			else if (i == argn - 3 - arguments.here_doc - 1)
				child_last(arguments, fds, env, argn);
			else
				exec_commands(arguments, fds, env, i);
		}
	}
	ft_wait(arguments, argn, pid, fds);
	pipex_free(fds, pid, argn - 3 - arguments.here_doc - 1, 5);
}

int	ft_pipex(int argn, char **argv, char **env)
{
	t_arguments_bonus	arguments;
	int					**fds;

	arguments = check_arg_bonus(argn, argv, env);
	fds = piping(arguments, argn);
	if (ft_strncmp(arguments.argv[1] , "here_doc", 8) == 0)
		dup_here(argv);
	pipex(arguments, argn, fds, env);
	fds_free(fds, argn - 3 - arguments.here_doc - 1, 5);
	free_arguments_bonus(&arguments);
	exit(0);
	return (0);

	//+++++++++++++++++//
	//MIRAR LAS CABECERAS
	//+++++++++++++++++//
}
