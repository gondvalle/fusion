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

size_t	where_path(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_error(ENV, NULL);
	return (0);
}

char	*first_word(char *arg)
{
	char	*word;
	char	**complete;

	complete = ft_split(arg, ' ');
	if (!complete)
		ft_error(MALLOC, NULL);
	word = ft_strdup(complete[0]);
	if (!word)
		ft_error(MALLOC, NULL);
	ft_free(complete);
	return (word);
}
