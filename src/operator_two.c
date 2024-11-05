/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:44:10 by gdel-val          #+#    #+#             */
/*   Updated: 2024/10/21 21:44:15 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	heredoc(char *del, int *fd, int stdin_copy)
{
	char	*here;
	char	*delimitier;

	delimitier = ft_strjoin(del, "\n");
	if (!delimitier)
		ft_error(MALLOC, NULL);
	while (1)
	{
		ft_putstr_fd(">", stdin_copy);
		here = get_next_line(stdin_copy);
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

void	mini_here(char *del, int stdin_copy)
{
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error(PIPE, NULL);
	heredoc(del, fd, stdin_copy);
	if (dup2(fd[READ], STDIN_FILENO) == -1)
		ft_error(DUP, NULL);
}

void	mini_append(char *commands, int stdout_copy)
{
	int	out_fd;

	out_fd = open(commands, O_CREAT | O_APPEND | O_RDWR, 0644);
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

void	ft_stdinout(char **commands, char **env)
{
	int	i;
	int	stdout_copy;
	int	stdin_copy;

	stdin_copy = dup(STDIN_FILENO);
	stdout_copy = dup(STDOUT_FILENO);
	i = -1;
	while (commands[++i] && commands[i + 1])
	{
		if (ft_strncmp(commands[i], "<<", 2) == 0)
			mini_here(commands[++i], stdin_copy);
		else if (ft_strncmp(commands[i], "<", 1) == 0)
			mini_in(commands[++i], stdin_copy);
		else if (ft_strncmp(commands[i], ">>", 2) == 0)
			mini_append(commands[++i], stdout_copy);
		else if (ft_strncmp(commands[i], ">", 1) == 0)
			mini_out(commands[++i], stdout_copy);
	}
	exec_stdinout(commands, env, stdin_copy, stdout_copy);
}

void	ft_operator(char **commands, char *here, char **env)
{
	char	*src;
	char	**mat_pipe;
	int		num_commands;

	src = clean_line(here);
	if (ft_strnstr(src, "|", ft_strlen(src)))
	{
		mat_pipe = ft_split(src, '|');
		if (!mat_pipe)
			ft_error(MALLOC, NULL);
		num_commands = count_pipes(src) + 1;
		execute_multiple_pipes(&mat_pipe, num_commands);
		ft_free(mat_pipe);
	}
	else
		ft_stdinout(commands, env);
	free(src);
}
