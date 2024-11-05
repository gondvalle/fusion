/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:38:04 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/03 18:32:16 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	contp(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i++;
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static size_t	len_word(char const *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i++])
		j++;
	return (j);
}

static char	**ft_free(char **mat)
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

static char	**minisplit(char const *s, char c, int i, int k)
{
	int		j;
	char	**mat;

	j = 0;
	mat = ft_calloc(contp(s, c) + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	while (s[++i] != '\0' && k < contp(s, c) - 1)
	{
		mat[++k] = ft_calloc(len_word(s, i, c) + 1, sizeof(char));
		if (!mat[k])
			return (ft_free(mat));
		j = 0;
		while (s[i] != c && s[i] != '\0' && mat[k])
			mat[k][j++] = s[i++];
		if (j == 0 && mat[k])
		{
			free(mat[k]);
			k--;
		}
		if (s[i] == '\0')
			i--;
	}
	return (mat);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	k;

	i = -1;
	k = i;
	if (!s)
		return (NULL);
	return (minisplit(s, c, i, k));
}
/*
int main() 
{
	const char *cadena = "      split       this for   me  !";
    //const char *cadena = "      split       this for   me  !     ";
    char **resultado = ft_split(cadena, ' ');
    for (int i = 0; resultado[i] != NULL; i++) {
        printf("Elemento %d: %s\n", i, resultado[i]);
        free(resultado[i]);  // Liberamos la memoria de cada elemento
		}

    free(resultado);
    return 0;
}*/
