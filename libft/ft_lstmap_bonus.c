/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:57:33 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/07 23:26:26 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *newlst;
	t_list *newlst_head;

	tmp = NULL;
	newlst_head = NULL;
	if (lst)
	{
		if (!(newlst = ft_lstnew(f(lst->content))))
			return (NULL);
		newlst_head = newlst;
		tmp = lst->next;
		while (tmp)
		{
			newlst->next = ft_lstnew(f(tmp->content));
			if (!newlst->next)
			{
				ft_lstclear(&newlst_head, del);
				return (NULL);
			}
			tmp = tmp->next;
			newlst = newlst->next;
		}
	}
	return (newlst_head);
}
