/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:12:00 by gdel-val          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:00 by gdel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list *node = malloc(sizeof(t_list));
	node->content = malloc(10);

	printf("node->content: %p\n", node->content);
	printf("node: %p\n", node);

	ft_lstdelone(node, del_func);

	printf("node->content: %p\n", node->content);
	printf("node: %p\n", node);

	return (0);
}*/
