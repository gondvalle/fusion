/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 02:58:35 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 18:45:39 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	num;

	num = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (n < i || n == 0)
		return (j + n);
	while (src[num] != '\0' && i + num < n - 1)
	{
		dst[i + num] = src[num];
		num++;
	}
	dst[i + num] = '\0';
	return (i + j);
}
/*
int main(void)
{
	char dst[20] = "Hola ";
	char src[] = "mundo";
	size_t len = ft_strlcat(dst, src, 20);

	printf("Concatenada: %s\n", dst);
	printf("tamaño: %zu\n", len);

	return (0);
}*/
