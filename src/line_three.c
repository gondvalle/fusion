/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/25 23:02:02 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*mat_to_line(char **mat)
{
	char	*result;
	int		total_len;
	int		i;
	int		j;
	int		k;

	total_len = 0;
	i = -1;
	while (mat[++i])
		total_len += ft_strlen(mat[i]);
	result = ft_calloc((total_len + ft_matlen(mat) + 1), sizeof(char));
	if (!result)
		ft_error(MALLOC, NULL);
	i = -1;
	k = -1;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
			result[++k] = mat[i][j];
		if (mat[i + 1])
			result[++k] = ' ';
	}
	result[++k] = '\0';
	return (result);
}

char	*dollar_line(char	*src)
{
	char	**dollar;
	char	**dol;
	char	*line;

	dol = quote_split_first(src);
	dollar = change_mat(dol);
	free(src);
	ft_free(dol);
	line = mat_to_line(dollar);
	ft_free(dollar);
	return (line);
}

char	**line_split(char *line)
{
	char	*clean;
	char	**mat;
	char	*dol_line;

	clean = clean_line(line);
	dol_line = dollar_line(clean);
	mat = ft_quotesplit(dol_line);
	free(dol_line);
	return (mat);
}
