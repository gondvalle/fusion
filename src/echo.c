/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marherra <marherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by ***********       #+#    #+#             */
/*   Updated: 2024/09/18 18:22:45 by marherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	n_control(char *src)
{
	int	i;

	if (!src)
		return (1);
	if (src[0] != '-')
		return (1);
	i = 0;
	while (src[++i])
		if (src[i] != 'n')
			return (1);
	return (0);
}

void	ft_echo(char **mat)
{
	size_t	i;
	int		ind;
	size_t	size;

	i = 0;
	ind = 0;
	size = 0;
	while (mat[size])
		size++;
	while (n_control(mat[++i]) == 0)
		ind = 1;
	while (mat[i] && i < size)
	{
		ft_putstr_fd(mat[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	if (mat[i])
		ft_putstr_fd(mat[i], 1);
	if (ind == 0)
		ft_putstr_fd("\n", 1);
}
