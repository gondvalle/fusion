/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:39:11 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/16 20:00:28 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*src;

	if (nmemb * size >= SIZE_MAX)
		return (NULL);
	src = malloc(nmemb * size);
	if (src == NULL)
		return (NULL);
	ft_bzero(src, nmemb * size);
	return (src);
}
/*
int main(void)
{
    char	*arr;

    arr = ft_calloc(5, sizeof(char));
    if (arr == NULL)
        printf("Error: asignación de memoria fallida.\n");
}
*/
