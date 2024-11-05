/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:43:25 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/31 14:56:00 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **str, char **str1, char **str2)
{
	if (str && *str)
	{
		free((*str));
		(*str) = NULL;
	}
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (NULL);
}

char	*string(int fd, char *src)
{
	char	*buffer;
	long	num;
	char	*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&src, 0, 0));
	while (!ft_strchr_gnl(src, '\n'))
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num < 0)
			return (ft_free(&src, &buffer, 0));
		if (num == 0)
			return (ft_free(&buffer, 0, 0), src);
		buffer[num] = '\0';
		tmp = ft_strdup_gnl(src);
		if (!tmp)
			return (ft_free(&src, &buffer, 0));
		ft_free(&src, 0, 0);
		src = ft_strjoin_gnl(tmp, buffer);
		if (!src)
			return (ft_free(&buffer, &tmp, 0));
		ft_free(&tmp, 0, 0);
	}
	return (ft_free(&buffer, 0, 0), src);
}

char	*copyjump(int fd, char *line, char *tmp, char **src)
{
	(*src) = string(fd, (*src));
	if (ft_strchr_gnl((*src), '\n'))
	{
		line = substr_gnl((*src), 0, ft_strchr_gnl((*src), '\n') - (*src) + 1);
		if (!line)
			return (ft_free(0, &(*src), 0));
		tmp = ft_strdup_gnl(ft_strchr_gnl((*src), '\n') + 1);
		if (!tmp)
			return (ft_free(&line, &(*src), 0));
		(*src) = ft_free(&(*src), 0, 0);
		(*src) = ft_strdup_gnl(tmp);
		if (!(*src))
			return (ft_free(0, &line, &tmp));
		tmp = ft_free(&tmp, 0, 0);
	}
	else if ((*src))
	{
		line = ft_strdup_gnl((*src));
		if (!line)
			return (ft_free(&(*src), 0, 0));
		(*src) = ft_free(&(*src), 0, 0);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*src;
	char		*line;
	char		*tmp;
	char		*dst;

	line = 0;
	tmp = 0;
	if (fd < 0 || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE < 1
		|| read(fd, 0, 0) < 0)
		return (ft_free(&src, 0, 0));
	dst = copyjump(fd, line, tmp, &src);
	if (!dst)
		return (ft_free(0, &line, &tmp));
	if (*dst == '\0')
		return (ft_free(&dst, &line, &tmp));
	return (dst);
}
