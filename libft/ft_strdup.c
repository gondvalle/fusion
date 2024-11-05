/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:53:57 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:36:52 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*src;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	src = malloc(i + 1);
	if (src == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
/*
int main(void)
{
    const char *original = "Hola, mundo!";
    char *duplicado = ft_strdup(original);

    printf("Original: %s\n", original);
    printf("Duplicado: %s\n", duplicado);

    // Liberar la memoria asignada
    free(duplicado);

    return (0);
}*/
