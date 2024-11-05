/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:52:06 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 21:03:57 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list *lista = NULL;

	t_list *nodo1 = malloc(sizeof(t_list));
	t_list *nodo2 = malloc(sizeof(t_list));
	nodo1->content = "Nodo 1";
	nodo1->next = NULL;
	nodo2->content = "Nodo 2";
	nodo2->next = NULL;
	ft_lstadd_front(&lista, nodo2);
	ft_lstadd_front(&lista, nodo1);

	t_list *temp = lista;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	free(nodo1);
	free(nodo2);
	return (0);
}*/
