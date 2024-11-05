/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:35:35 by gdel-val          #+#    #+#             */
/*   Updated: 2024/09/18 18:30:50 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		num;

	i = 0;
	if (!n)
		return (0);
	num = (unsigned char)s1[i] - (unsigned char)s2[i];
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			num = (unsigned char)s1[i] - (unsigned char)s2[i];
			break ;
		}
		i++;
	}
	return (num);
}
/*
int main(void)
{
	const char *str1 = "Hola";
	const char *str2 = "Hola, Mundo!";
	size_t n = 5;
	int result_ft = ft_strncmp(str1, str2, n);

	printf("Resultado: %d\n", result_ft);
}*/
