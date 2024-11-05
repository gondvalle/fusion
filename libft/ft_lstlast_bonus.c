/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:40:34 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 21:10:49 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*list;

	i = 0;
	list = lst;
	while (i < ft_lstsize(lst) - 1)
	{
		list = list->next;
		i++;
	}
	return (list);
}
/*
int main()
{
    t_list *nodo1 = malloc(sizeof(t_list));
    t_list *nodo2 = malloc(sizeof(t_list));
    t_list *nodo3 = malloc(sizeof(t_list));

    nodo1->content = "Nodo 1";
    nodo1->next = nodo2;
    nodo2->content = "Nodo 2";
    nodo2->next = nodo3;
    nodo3->content = "Nodo 3";
    nodo3->next = NULL;
    t_list *ultimoNodo = ft_lstlast(nodo1);
    printf("Contenido del último nodo: %s\n", (char *)ultimoNodo->content);
    free(nodo1);
    free(nodo2);
    free(nodo3);
    return (0);
}*/
