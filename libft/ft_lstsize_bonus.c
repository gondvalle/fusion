/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:22:07 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/02 21:07:13 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
    printf("Tamaño de la lista: %d\n", ft_lstsize(nodo1));
    free(nodo1);
    free(nodo2);
    free(nodo3);
    return 0;
}*/
