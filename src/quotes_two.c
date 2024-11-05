/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/10/07 17:49:19 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*clean_other(char *str)
{
	int		i;
	int		j;
	char	*cl_other;
	char	*line;

	cl_other = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!cl_other)
		ft_error(MALLOC, NULL);
	line = quote_line(str);
	if (!line)
		ft_error(MALLOC, NULL);
	i = -1;
	j = -1;
	while (line[++i])
	{
		if (line[i] == 'c')
			continue ;
		cl_other[++j] = line[i];
	}
	free(line);
	return (cl_other);
}
