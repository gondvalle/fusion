/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:31:01 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/18 20:57:18 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main() {
    t_list *list;
    list = NULL;

    char *element1 = strdup("Element 1");
    char *element2 = strdup("Element 2");
    char *element3 = strdup("Element 3");

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1->content = element1;
    node2->content = element2;
    node3->content = element3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    list = node1; 

    printf("Mio del nodo 2: %s\n", (node2->content));

    ft_lstiter(list, change_content);

    printf("Ori nodo 2: %s\n", (node2->content));

    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp->content);
        free(temp);
    }

    return 0;
}*/
