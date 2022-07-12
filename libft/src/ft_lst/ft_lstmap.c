/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:26:33 by obenjair          #+#    #+#             */
/*   Updated: 2022/07/03 02:48:09 by obenjair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*orig;
	t_list	*newlist;

	newlist = NULL;
	orig = lst;
	while (orig)
	{
		newnode = ft_lstnew(f(orig->content));
		if (newnode)
			ft_lstadd_back(&newlist, newnode);
		else
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		orig = orig->next;
	}
	return (newlist);
}
