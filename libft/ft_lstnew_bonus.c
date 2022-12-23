/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:58:57 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/04 17:17:08 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *next;

	next = (t_list*)malloc(sizeof(t_list));
	if (next == NULL)
		return (NULL);
	next->content = content;
	next->next = NULL;
	return (next);
}
