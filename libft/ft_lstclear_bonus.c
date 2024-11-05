/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:22:02 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/18 20:55:36 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*start;

	start = *lst;
	while (start)
	{
		tmp = start->next;
		del(start->content);
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
/*
int main() {
    t_list *list;
    list = NULL;

    t_list *element1 = ft_lstnew("Element 1");
    t_list *element2 = ft_lstnew("Element 2");
    t_list *element3 = ft_lstnew("Element 3");

    ft_lstadd_front(&list, element3);
    ft_lstadd_front(&list, element2);
    ft_lstadd_front(&list, element1);

    while (list) {
        printf("%s\n", (char *)(list->content));
        list = list->next;
    }

    ft_lstclear(&list, free);

    while (list == NULL)
        return(printf("Vacio\n"));

    return 0;
}*/
