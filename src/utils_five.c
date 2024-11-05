/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/30 22:22:33 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	mini_qte_two(char *str, char *lit, int clsd, int clss)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' && clsd == 1)
		{
			clss = clss * -1;
			lit[i] = 'c';
		}
		else if (str[i] == '\"' && clss == 1)
		{
			clsd = clsd * -1;
			lit[i] = 'c';
		}
		else if (str[i] == ' ' && clss == 1 && clsd == 1)
			lit[i] = ' ';
		else if (str[i] == '$')
			lit[i] = '$';
		else if (clss == -1)
			lit[i] = 's';
		else
			lit[i] = 'n';
	}
}

char	*quote_line_two(char *str)
{
	int		close_s;
	int		close_d;
	char	*lit;

	lit = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!lit)
		ft_error(MALLOC, NULL);
	close_s = 1;
	close_d = 1;
	mini_qte_two(str, lit, close_d, close_s);
	return (lit);
}

char	**qout_mat(char *src)
{
	char	**mat_qout;
	char	*qoute_str;
	char	*str;
	int		i;

	qoute_str = quote_line_two(src);
	i = -1;
	while (qoute_str[++i])
		if (qoute_str[i] == '$')
			break ;
	str = ft_substr(qoute_str, i, ft_strlen(qoute_str));
	mat_qout = ft_split(str, '$');
	free(str);
	free(qoute_str);
	return (mat_qout);
}

char	*mini_env_dollar(char *src)
{
	char	**mat;
	char	*str;
	char	*join;
	char	*copy;
	char	**matqoute;

	copy = copy_character(src, '$');
	mat = split_pointer(src);
	if (!mat)
		ft_error(MALLOC, NULL);
	matqoute = qout_mat(src);
	str = change_dollar(mat, src, matqoute);
	ft_free(matqoute);
	ft_free(mat);
	join = ft_strjoin(copy, str);
	free(copy);
	free(str);
	if (!join)
		ft_error(MALLOC, NULL);
	return (join);
}

char	*env_dollar(char *src)
{
	char	**mat;
	char	*str;
	char	**matqoute;

	if (ft_strncmp(src, "$", 1) != 0)
	{
		str = mini_env_dollar(src);
		return (str);
	}
	mat = ft_split(src, '$');
	if (!mat)
		ft_error(MALLOC, NULL);
	matqoute = qout_mat(src);
	str = change_dollar(mat, src, matqoute);
	ft_free(matqoute);
	ft_free(mat);
	return (str);
}
