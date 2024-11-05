/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:55:10 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 17:50:48 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int main()
{
    char test_chars[] = {'A', 'b', '5', '$', 'C'};
	int	i;
	
	i = 0;
    while (i < 5) 
	{
        if (ft_isalpha(test_chars[i]))
            printf("%c is a letter.\n", test_chars[i]);
     	else
            printf("%c is not a letter.\n", test_chars[i]);
		i++;
    }
    return (0);
}*/
