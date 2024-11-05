/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/23 21:12:49 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_free(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		mat[i] = NULL;
		i++;
	}
	free(mat);
	mat = NULL;
	return (NULL);
}

int	ft_fullcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		num;

	i = 0;
	if (!s1 || !s2)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	num = (unsigned char)s1[i] - (unsigned char)s2[i];
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			num = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (num);
}

char	*ft_nulljoin(char *s1, char *s2)
{
	char	*src;

	if (!s2)
		return (s1);
	src = ft_strjoin_gnl(s1, s2);
	if (!src)
		ft_error(MALLOC, NULL);
	return (src);
}

char	*copy_character(char *src, char c)
{
	char	*copy;
	size_t	i;

	while (src[0] == c)
		return (NULL);
	i = 0;
	while (src[i] != c)
		i++;
	copy = ft_calloc(i + 1, sizeof(char));
	if (!copy)
		ft_error(MALLOC, NULL);
	i = 0;
	while (src[i] != c)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t	dollar_size(char **mat, char *src, char **matqoute)
{
	size_t	i;
	size_t	j;
	char	*tmp;
	char	*otmp;

	i = -1;
	j = 0;
	while (mat[++i])
	{
		if (matqoute[i][0] == 'n')
		{
			tmp = dollar_env(mat[i]);
			if (tmp)
				j = j + ft_strlen(tmp);
			otmp = dollar_digit(mat[i]);
			if (otmp)
				j = j + ft_strlen(otmp);
			free(otmp);
		}
		else
			j = j + ft_strlen(mat[i]) + 1;
	}
	if (src[ft_strlen(src) - 1] == '$')
		j++;
	return (j);
}
