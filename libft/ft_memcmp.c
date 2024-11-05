/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:55:17 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 19:25:06 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t	i;
	int		num;

	i = 0;
	if (!n)
		return (0);
	num = ((unsigned char *)dest)[i] - ((unsigned char *)src)[i];
	while (i < n)
	{
		if (((unsigned char *)dest)[i] != ((unsigned char *)src)[i])
		{
			num = ((unsigned char *)dest)[i] - ((unsigned char *)src)[i];
			break ;
		}
		i++;
	}
	return (num);
}
/*
int main(void)
{
    const char *str1 = "Hola Mundo";
    const char *str2 = "Hola A";

    int result_ft = ft_memcmp(str1, str2, 10);
    int result_mem = memcmp(str1, str2, 10);

    printf("Resultado de ft_memcmp: %d\n", result_ft);
    printf("Resultado de memcmp: %d\n", result_mem);
}*/
