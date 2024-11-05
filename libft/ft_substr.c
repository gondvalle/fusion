/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:43:51 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/03 16:23:10 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	src = malloc(len + 1);
	if (src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		src[i] = s[start + i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
/*
int main(void)
{
    const char *original = "Esta es una cadena de ejemplo.";
    char *substring = ft_substr(original, 5, 10);

    printf("Subcadena: %s\n", substring);
    free(substring);
    return (0);
}*/
