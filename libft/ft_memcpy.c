/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 00:28:39 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 18:34:25 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_dst;
	const char	*src_src;

	i = 0;
	dst_dst = dst;
	src_src = src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		dst_dst[i] = src_src[i];
		i++;
	}
	return (dst);
}
/*
int main(void)
{
	char src[] = "Hello, World!";
	char dst[13];

	ft_memcpy(dst, src, 12);
	printf("Copied: %s\n", dst);

	return (0);
}*/
