/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:30:49 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 20:57:05 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = malloc(sizeof(t_list));
	if (!lista)
		return (NULL);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}
/*
int main()
{
	t_list *new_node = ft_lstnew("Hola");

	printf("nodo: %s\n", (char *)new_node->content);
	free(new_node);
	return (0);
}*/
