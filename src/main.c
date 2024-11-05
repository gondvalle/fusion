/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/10/09 20:30:52 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

volatile int g_signal_status = 0;

int	slash_token(char *str, char *quote)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '|' && quote[i] == 'n')
		{
			while (str[++i])
			{
				if (str[i] == '|' && quote[i] == 'n')
					return (1);
				if (str[i] != '|' && str[i] != ' ')
					return (0);
			}
		}
	}
	return (0);
}

int	check_tocken(char *str)
{
	int		i;
	char	*trim;
	char	*quote;

	if (!str)
		return (0);
	i = -1;
	trim = ft_strtrim(str, " ");
	if (!trim)
		ft_error(MALLOC, NULL);
	if (ft_strlen(trim) == 0)
		return (0);
	quote = quote_line(trim);
	if (!quote)
		return (frees(trim, quote), 1);
	while (trim[++i])
		if ((trim[i] == ';' || trim[i] == '\\') && quote[i] == 'n')
			return (printf("%s '%c'\n", TOKEN, trim[i]), frees(trim, quote), 1);
	if (trim[ft_strlen(trim) - 1] == '<' || trim[ft_strlen(trim) - 1] == '>')
		return (frees(trim, quote), printf("%s 'newline'\n", TOKEN), 1);
	if (slash_token(trim, quote) == 1)
		return (frees(trim, quote), printf("%s '|'\n", TOKEN), 1);
	frees(trim, quote);
	return (0);
}

int	main(int argn, char **argv, char **env)
{
	char	*here;
	char	*current;
	char	**commands;
	t_env_list *env_list = NULL;
	char *shell_path = "/bin/minishell";

	if (argn > 1 || argv[1])
		return (printf("Error: bad number of arguments\n"), 0);
	print_minishell();
	signal_handler(ft_sigint, ft_sigquit);
	if (initialize_environment(&env_list, env, shell_path) != 0)
		ft_error(ENVERROR, NULL);
	while (1)
	{
		current = first_line();
		here = readline(current);
		if (!here)
			break ;
		if (ft_strncmp(here, "exit", ft_strlen("exit")) == 0)
			break ;
		if (here && *here)
			add_history(here);
		if (check_tocken(here) == 1)
		{
			free(here);
			free(current);
			continue;
		}
		commands = line_split(here);
		if (ft_fullcmp(commands[0], "cd") == 0)
			change_cd(commands);
		else if (search_op(here))
			ft_operator(commands, here, env);
		else if (ft_fullcmp(commands[0], "echo") == 0)
			ft_echo(commands);
		else if (ft_fullcmp(commands[0], "pwd") == 0)
			ft_pwd();
		else if (!commands[0])
		{
			free(here);
			free(current);
			ft_free(commands);
			continue ;
		}
		else
			ft_command(commands, env);
		free(here);
		free(current);
		ft_free(commands);
	}
	free(here);
	free(current);
	clear_history();
	exit(0);
	return (0);
}
