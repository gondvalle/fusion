/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:53:56 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:35:16 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	size_t	i;

	i = 0;
	src = malloc(ft_strlen(s) + 1);
	if (!src)
		return (NULL);
	while (s[i])
	{
		src[i] = f(i, s[i]);
		i++;
	}
	src[i] = '\0';
	return (src);
}
/*
char add_one(unsigned int index, char c)
{
   	if (c >= 'a' && c <= 'z')
       	return (c - 32);
	else
		return (c);
}

int main(void)
{
    const char *src = "hola que tal";
    char *fin = ft_strmapi(src, add_one);

    printf("Cadena transformada: %s\n", fin);
    free(fin);
    return (0);
}*/
