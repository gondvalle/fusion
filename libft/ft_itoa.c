/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:22:28 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:23:38 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	valabs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

static int	condig(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		i++;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*src;

	i = condig(n);
	src = malloc(i + 1);
	if (!src)
		return (NULL);
	src[0] = '0';
	src[condig(n)] = '\0';
	if (n < 0)
		src[0] = '-';
	while (n != 0)
	{
		src[i - 1] = valabs(n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (src);
}
/*
int main(void)
{
    int num = -2147483648;
    char *str = ft_itoa(num);

    printf("Número convertido a cadena: %s\n", str);
    free(str);
    return (0);
}*/
