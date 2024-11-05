/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:28:56 by gdel-val          #+#    #+#             */
/*   Updated: 2023/09/26 20:34:59 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	comfra(char const *s1, char const *set)
{
	int		i;
	size_t	j;
	int		d;

	i = 0;
	d = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (j <= ft_strlen(set))
		{
			if (s1[i] == set[j])
			{
				d = 1;
				break ;
			}
			j++;
		}
		if (d == 0)
			return (i);
		d = 0;
		i++;
	}
	return (i);
}

static size_t	finfra(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	d;

	i = ft_strlen(s1) - 1;
	d = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				d = 1;
				break ;
			}
			j++;
		}
		if (d == 0)
			return (i + 1);
		d = 0;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*srr;

	i = 0;
	if (comfra(s1, set) == ft_strlen(s1))
		return (ft_strdup(""));
	srr = ft_calloc(finfra(s1, set) - comfra(s1, set) + 1, 1);
	if (srr == NULL)
		return (NULL);
	while (i < finfra(s1, set) - comfra(s1, set))
	{
		srr[i] = s1[i + comfra(s1, set)];
		i++;
	}
	srr[i] = '\0';
	return (srr);
}
/*
int main() {
    // Cadena de ejemplo con espacios en blanco al principio y al final
    const char *input_str = "lorem ipsum dolor sit amet";

    // Conjunto de caracteres a eliminar (espacios en blanco en este caso)
    const char *trim_set = "tel";

    // Llama a la función ft_strtrim para eliminar espacios en blanco
    char *trimmed_str = ft_strtrim(input_str, trim_set);

    if (trimmed_str) {
        printf("Cadena original: \"%s\"\n", input_str);
        printf("Cadena recortada: \"%s\"\n", trimmed_str);
        free(trimmed_str); // Liberar memoria asignada dinámicamente
    } else {
        printf("La asignación de memoria falló.\n");
    }

    return 0;
}*/
