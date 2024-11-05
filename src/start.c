/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/18 19:01:42 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_minishell(void)
{
	ft_putstr_fd("\033[38;5;82m=========================================\033[m", 1);
	ft_putstr_fd("\033[38;5;82m=========================================\033[m\n", 1);
	ft_putstr_fd("\033[38;5;82m.___  ___.  __  .__   __.  __       _____\033[m", 1);
	ft_putstr_fd("\033[38;5;82m__. __    __   _______  __       __\033[m\n", 1);
	ft_putstr_fd("\033[38;5;118m|   \\/   | |  | |  \\ |  | |  |     /   \033[m", 1);
	ft_putstr_fd("\033[38;5;118m    ||  |  |  | |   ____||  |     |  |\033[m\n", 1);
	ft_putstr_fd("\033[38;5;154m|  \\  /  | |  | |   \\|  | |  |    |   (\033[m", 1);
	ft_putstr_fd("\033[38;5;154m----`|  |__|  | |  |__   |  |     |  |     \033[m\n", 1);
	ft_putstr_fd("\033[38;5;190m|  |\\/|  | |  | |  . `  | |  |     \\   \033[m", 1);
	ft_putstr_fd("\033[38;5;190m\\    |   __   | |   __|  |  |     |  |\033[m\n", 1);
	ft_putstr_fd("\033[38;5;226m|  |  |  | |  | |  |\\   | |  | .----)   \033[m", 1);
	ft_putstr_fd("\033[38;5;226m|   |  |  |  | |  |____ |  `----.|  `----.\033[m\n", 1);
	ft_putstr_fd("\033[38;5;220m|__|  |__| |__| |__| \\__| |__| |_______/  \033[m", 1);
	ft_putstr_fd("\033[38;5;220m  |__|  |__| |_______||_______||_______|\033[m\n\n", 1);
	ft_putstr_fd("\033[38;5;82m===============================gdel-val\033[m", 1);
	ft_putstr_fd("\033[38;5;82m & marherra================================\033[m\n", 1);
}

char	*current_directory(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		ft_error("getcwd() error", NULL);
		return (NULL);
	}
	return (cwd);
}

char	*replace_pwd(void)
{
	char	*user;
	char	*current;
	char	*home;
	char	*line;

	user = ft_get_env("USER");
	if (!user)
		ft_error(ENV, NULL);
	current = current_directory();
	home = ft_get_env("HOME");
	if (!home)
		ft_error(ENV, NULL);
	line = ft_replace(current, home, '~');
	free(current);
	return (line);
}

char	*first_line(void)
{
	char	*tmp;
	char	*other_tmp;
	char	*pwd;
	char	*user;
	char	*line;

	user = ft_get_env("USER");
	pwd = replace_pwd();
	tmp = ft_threejoin("\033[32m", user, "@minishell \033[0m");
	other_tmp = ft_threejoin("\033[34m", pwd, "\033[0m $ ");
	line = ft_strjoin(tmp, other_tmp);
	if (!line)
	{
		free(tmp);
		free(pwd);
		free(other_tmp);
		return (NULL);
	}
	free(tmp);
	free(pwd);
	free(other_tmp);
	return (line);
}
