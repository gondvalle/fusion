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

void	ft_pwd(void)
{
	char	*src;

	src = current_directory();
	if (!src)
		printf("NO PWD\n");
	else
		printf("%s\n", src);
	free(src);
}

void	frees(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

char	*shell_strnstr(char *stack, char *needle, size_t len, char *qte)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (stack == needle || needle[0] == '\0')
		return ((char *)stack);
	while (stack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == stack[i + j] && i + j < len && qte[i + j] == 'n')
		{
			if (needle[j + 1] == '\0')
				return ((char *)stack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*search_op(char *src)
{
	char	*quote;

	quote = quote_line(src);
	if (!quote)
		ft_error(MALLOC, NULL);
	if (shell_strnstr(src, "<", ft_strlen(src), quote))
		return (free(quote), src);
	if (shell_strnstr(src, ">", ft_strlen(src), quote))
		return (free(quote), src);
	if (shell_strnstr(src, "<<", ft_strlen(src), quote))
		return (free(quote), src);
	if (shell_strnstr(src, ">>", ft_strlen(src), quote))
		return (free(quote), src);
	if (shell_strnstr(src, "|", ft_strlen(src), quote))
		return (free(quote), src);
	return (free(quote), NULL);
}

char	**split_pointer(char *src)
{
	char	*point;
	char	**mat;

	point = ft_strchr(src, '$');
	mat = ft_split(point, '$');
	return (mat);
}
