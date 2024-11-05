/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:46:34 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 18:19:53 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_dst;
	const char	*src_src;

	i = -1;
	dst_dst = dst;
	src_src = src;
	if (!n || dst == src)
		return (dst);
	if (src + n > dst && src < dst)
	{
		while (n > 0)
		{
			dst_dst[n - 1] = src_src[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			dst_dst[i] = src_src[i];
	}
	return (dst);
}
/*
int main(void)
{
	char str[30] = "hola que tal";

	ft_memmove(str + 5, str, 10);
	printf("Después: %s\n", str);

	return (0);
}*/
