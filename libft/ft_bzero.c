/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:27:31 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 18:11:24 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int main()
{
    char str[20] = "Hola, Mundo!";
	size_t num = 10;

    ft_bzero(str, num);

    printf("Después de ft_bzero: %s\n", str);

    return (0);
}*/
