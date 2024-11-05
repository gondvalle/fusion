/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:37:47 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:52:39 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			c = n % 10 + '0';
			ft_putnbr_fd(n / 10, fd);
			write(fd, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			write(fd, &c, 1);
		}
	}
}
/*
int main()
{
    int number = 2147483647;

    ft_putnbr_fd(number, 1);
    return (0);
}*/
