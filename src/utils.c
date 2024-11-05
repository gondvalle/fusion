/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/23 18:58:48 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*BORRARBORRARBORRARBORRARBORRAR*/
void	print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
/*BORRARBORRARBORRARBORRARBORRAR*/

void	ft_error(char *str, char *file)
{
	char	*msg;

	if (file)
	{
		msg = ft_strjoin(str, file);
		if (!msg)
			return (perror("Error\n"));
		ft_putstr_fd(msg, 2);
	}
	else
		ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

char	*ft_threejoin(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		ft_error(MALLOC, NULL);
	str = ft_strjoin(tmp, s3);
	if (!str)
	{
		free(tmp);
		ft_error(MALLOC, NULL);
	}
	free(tmp);
	return (str);
}

char	*ft_get_env(char *get)
{
	char	*var;

	if (!get)
		return (NULL);
	var = getenv(get);
	if (var != NULL)
		return (var);
	return (NULL);
}

char	*ft_strstrend(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i + j);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_replace(const char *haystack, const char *needle, const char rplc)
{
	char	*pnt;
	char	*rpl;
	char	*str;

	if (ft_strlen(haystack) < ft_strlen(needle))
		return ((char *)haystack);
	pnt = ft_strstrend(haystack, needle);
	if (!pnt)
	{
		str = ft_strdup(haystack);
		return (str);
	}
	rpl = ft_strdup(pnt);
	if (!rpl)
		ft_error(MALLOC, NULL);
	rpl[0] = rplc;
	return (rpl);
}
