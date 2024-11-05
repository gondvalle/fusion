/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/23 19:36:11 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**clean_in(char **commands)
{
	int		i;
	int		j;
	char	**mat;

	i = -1;
	j = 0;
	while (commands[++i])
		if (ft_strncmp(commands[i], "<", 1) != 0
			&& (i == 0 || ft_strncmp(commands[i - 1], "<", 1) != 0))
			j++;
	mat = ft_calloc(j + 1, sizeof(char *));
	if (!mat)
		ft_error(MALLOC, NULL);
	i = -1;
	j = -1;
	while (commands[++i])
		if (ft_strncmp(commands[i], "<", 1) != 0
			&& (i == 0 || ft_strncmp(commands[i - 1], "<", 1) != 0))
			mat[++j] = ft_strdup(commands[i]);
	return (mat);
}

char	**clean_out(char **commands)
{
	int		i;
	int		j;
	char	**mat;

	i = -1;
	j = 0;
	while (commands[++i])
		if (ft_strncmp(commands[i], ">", 1) != 0
			&& (i == 0 || ft_strncmp(commands[i - 1], ">", 1) != 0))
			j++;
	mat = ft_calloc(j + 1, sizeof(char *));
	if (!mat)
		ft_error(MALLOC, NULL);
	i = -1;
	j = -1;
	while (commands[++i])
		if (ft_strncmp(commands[i], ">", 1) != 0
			&& (i == 0 || ft_strncmp(commands[i - 1], ">", 1) != 0))
			mat[++j] = ft_strdup(commands[i]);
	return (mat);
}

void	exec_stdinout(char **commands, char **env, int stdin, int stdout)
{
	char	**mat;
	char	**tmp;

	tmp = clean_in(commands);
	mat = clean_out(tmp);
	ft_free(tmp);
	if (mat[0])
	{
		ft_command(mat, env);
		ft_free(mat);
	}
	if (dup2(stdin, STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
	if (dup2(stdout, STDOUT_FILENO) == -1)
		ft_error(DUP, NULL);
	close(stdout);
}

void	mini_in(char *commands, int stdin_copy)
{
	int	in_fd;

	in_fd = open(commands, O_RDONLY);
	if (in_fd < 0)
	{
		printf("-bash: %s: No such file or directory\n", commands);
		if (dup2(stdin_copy, STDIN_FILENO) == -1)
			ft_error(DUP, NULL);
		return ;
	}
	if (dup2(in_fd, STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
	close(in_fd);
}

void	mini_out(char *commands, int stdout_copy)
{
	int	out_fd;

	out_fd = open(commands, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (out_fd < 0)
	{
		printf("-bash: %s: No such file or directory\n", commands);
		if (dup2(stdout_copy, STDIN_FILENO) == -1)
			ft_error(DUP, NULL);
		return ;
	}
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		ft_error(DUP, NULL);
	close(out_fd);
}
