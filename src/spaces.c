/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/30 21:35:10 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ind_space(char input_f, char quote, char input_l)
{
	int	ind;

	ind = 0;
	if (((input_f == '<' && input_l != '<')
			|| (input_f == '>' && input_l != '>')
			|| (input_f == '|' && input_l != '|'))
		&& quote == 'n' && input_l != ' ')
		ind = 1;
	return (ind);
}

char	*add_spaces(char *input)
{
	char	*quote;
	char	*str;
	int		i;
	int		j;

	quote = quote_line(input);
	if (!quote)
		ft_error(MALLOC, NULL);
	str = ft_calloc((ft_strlen(input) * 2 + 1), sizeof(char));
	if (!str)
		ft_error(MALLOC, NULL);
	i = -1;
	j = -1;
	while (quote[++i])
	{
		if (i > 0 && ind_space(input[i], quote[i], input[i - 1]) == 1)
			str[++j] = ' ';
		str[++j] = input[i];
		if (ind_space(input[i], quote[i], input[i + 1]) == 1)
			str[++j] = ' ';
	}
	free(quote);
	return (str);
}
