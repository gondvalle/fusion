/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:04:38 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:19:48 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*scr;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	scr = malloc(i + 1);
	if (scr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		scr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		scr[i] = s2[j];
		i++;
		j++;
	}
	scr[i] = '\0';
	return (scr);
}
/*
int main(void)
{
    const char *str1 = "Hola, ";
    const char *str2 = "mundo!";
    char *resul = ft_strjoin(str1, str2);

    printf("Cadena concatenada: %s\n", resul);
    free(resul);
    return (0);
}*/
