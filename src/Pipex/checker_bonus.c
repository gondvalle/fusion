/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:36:23 by gdel-val          #+#    #+#             */
/*   Updated: 2024/07/22 19:36:25 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char **commands(t_arguments_bonus arguments, int argn, char **argv, char **env)
{
	char	**commands;
	int		i;

	i = -1;
	commands = ft_calloc(argn - 3 - arguments.here_doc + 1, sizeof(char *));
	if (!commands)
		ft_error(MALLOC, NULL);
	while (++i < argn  - 3 - arguments.here_doc)
	{
		commands[i] = command(env, argv[i + 2 + arguments.here_doc]);
		if (!commands[i])
			return(ft_free(commands));
	}
	return (commands);
}

char ***splits(t_arguments_bonus arguments, int argn, char **argv)
{
	char	***splits;
	int		i;

	i = -1;
	splits = ft_calloc(argn - 3 - arguments.here_doc + 1, sizeof(char **));
	while (++i < argn  - 3 - arguments.here_doc)
	{
		splits[i] = ft_split(argv[i + 2 + arguments.here_doc], ' ');
		if (!splits[i])
		{
			while (i >= 0)
			{
				ft_free(splits[i]);
				i--;
			}
			ft_error(MALLOC, NULL);
			return (0);
		}
	}
	return (splits);
}

t_arguments_bonus	check_here(int argn, char **argv)
{
	t_arguments_bonus	arguments;

	if (argn < 5)
		ft_error(ARGUMENTS, NULL);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		arguments.here_doc = 1;
	else
	{
		arguments.in_fd = open(argv[1], O_RDONLY);
		if (arguments.in_fd < 0)
			ft_error(FILE, argv[1]);
		arguments.here_doc = 0;
	}
	return (arguments);
}

t_arguments_bonus	check_arg_bonus(int argn, char **argv, char **env)
{
	t_arguments_bonus arguments;

	arguments = check_here(argn, argv);
	arguments.out_fd = open(argv[argn - 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (arguments.out_fd < 0)
		ft_error(FILE, argv[argn - 1]);
	arguments.commands = commands(arguments, argn, argv, env);
	arguments.splits = splits(arguments, argn, argv);
	arguments.argv = argv;
	return (arguments);
}