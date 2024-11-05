/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:28:04 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 19:22:59 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	size_t		i;

	i = 0;
	src = NULL;
	if (!n)
		return (0);
	while (((char *)s)[i] != (char)c && i < n - 1)
	{
		i++;
	}
	if (((char *)s)[i] == (char)c)
		src = (char *)&((char *)s)[i];
	return ((void *)src);
}
/*
int main(void)
{
	const char *str = "Hola, Mundo!";
	int character = 'a';
	void *result_ft = ft_memchr(str, character, ft_strlen(str));
	void *result_mem = memchr(str, character, ft_strlen(str));

	printf("Resultado de ft_memchr: %p\n", result_ft);
	printf("Resultado de memchr: %p\n", result_mem);

	return (0);
}*/
