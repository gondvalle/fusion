/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:30:32 by gdel-val          #+#    #+#             */
/*   Updated: 2024/10/21 21:30:37 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*check_first(char **env, char *arg)
{
	char	*command;
	char	**path;
	size_t	i;

	if (ft_strchr(arg, '/'))
	{
		command = ft_strdup(arg);
		if (!command)
			ft_error(MALLOC, NULL);
		return (command);
	}
	i = 0;
	path = path_env(env);
	while (path[i] != NULL)
	{
		command = ft_threejoin(path[i], "/", arg);
		if (access(command, F_OK | X_OK) == 0)
			return (ft_free(path), command);
		free(command);
		i++;
	}
	ft_free(path);
	printf("-bash: %s: command not found\n", arg);
	return (NULL);
}

void	ft_command(char	**mat, char **env)
{
	char	*command;
	pid_t	pid[1];

	command = check_first(env, mat[0]);
	if (!command)
		return ;
	pid[0] = fork();
	if (pid[0] == 0)
	{
		if (execve(command, mat, env) == -1)
			printf("%s: illegal option -- %s\n", command, mat[1]);
	}
	free(command);
	if (pid[0] == -1)
		ft_error(FORK, NULL);
	g_signal_status = waitpid(pid[0], NULL, 0);
}
