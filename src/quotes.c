/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/30 22:37:48 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	quote_close(char *str)
{
	int	i;
	int	close_s;
	int	close_d;

	i = -1;
	close_s = 1;
	close_d = 1;
	while (str[++i])
	{
		if (str[i] == '\'' && close_d == 1)
			close_s = close_s * -1;
		if (str[i] == '\"' && close_s == 1)
			close_d = close_d * -1;
	}
	if (close_s == -1)
		printf("Error single quote no close\n");
	if (close_d == -1)
		printf("Error double quote no close\n");
	if (close_s == -1 || close_d == -1)
		return (-1);
	return (1);
}

void	mini_qte(char *str, char *lit, int clsd, int clss)
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
		else if (clss == -1)
			lit[i] = 's';
		else if (clsd == -1)
			lit[i] = 'd';
		else
			lit[i] = 'n';
	}
}

char	*quote_line(char *str)
{
	int		close_s;
	int		close_d;
	char	*lit;

	if (quote_close(str) == -1)
		return (NULL);
	lit = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!lit)
		ft_error(MALLOC, NULL);
	close_s = 1;
	close_d = 1;
	mini_qte(str, lit, close_d, close_s);
	return (lit);
}

char	*clean_qt(char *str)
{
	int		i;
	int		j;
	char	*cl_line;
	char	*line;

	cl_line = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!cl_line)
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
		cl_line[++j] = str[i];
	}
	free(line);
	return (cl_line);
}
