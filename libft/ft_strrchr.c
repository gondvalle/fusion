/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 03:44:45 by gdel-val          #+#    #+#             */
/*   Updated: 2024/03/11 16:14:48 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*src;
	int			i;
	int			num;

	i = 0;
	src = NULL;
	num = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			num = i;
		i++;
	}
	if (s[i] == (char)c)
		num = i;
	if (num != -1 && s[num] == (char)c)
		src = (char *)&s[num];
	return ((char *)src);
}
/*
int main(void)
{
	const char *str = "¡Hola, Mundo!";
	char let = 'o';
	char *resul = ft_strrchr(str, let);

	printf("Posición: %ld\n", resul - str);
}*/
