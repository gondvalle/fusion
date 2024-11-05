/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:54:08 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 21:18:27 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
/*
int main()
{
    t_list *nodo1 = malloc(sizeof(t_list));
    t_list *nodo2 = malloc(sizeof(t_list));
    t_list *nodo3 = malloc(sizeof(t_list));

    nodo1->content = "Nodo 1";
    nodo1->next = NULL;
    nodo2->content = "Nodo 2";
    nodo2->next = NULL;
    t_list *miLista = NULL;
    ft_lstadd_front(&miLista, nodo1);
    ft_lstadd_back(&miLista, nodo2);
	miLista = miLista->next;
	printf("%s\n", (char *)miLista->content);
    free(nodo1);
    free(nodo2);
    free(nodo3);
    return (0);
}*/
