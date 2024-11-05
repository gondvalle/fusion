/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:40:41 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 19:37:49 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nscr)
{
	int	i;
	int	num;
	int	a;

	i = 0;
	num = 0;
	a = 1;
	while (nscr[i] == ' ' || nscr[i] == '\n' || nscr[i] == '\r'
		|| nscr[i] == '\t' || nscr[i] == '\v' || nscr[i] == '\f')
		i++;
	if (nscr[i] == '-' || nscr[i] == '+')
	{
		if (nscr[i] == '-')
			a = -1;
		i++;
	}
	while (nscr[i] != '\0')
	{
		if ('0' <= nscr[i] && nscr[i] <= '9')
			num = num * 10 + (nscr[i] - '0');
		else
			break ;
		i++;
	}
	return (a * num);
}
/*
int main(void)
{
    const char *num = "-2147483648";

	printf("Número: %i\n", ft_atoi(num));
}*/
