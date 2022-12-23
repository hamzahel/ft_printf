/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:18:11 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/09 20:43:05 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (*alst)
	{
		tmp = ft_lstlast(*alst);
		if (tmp)
		{
			tmp->next = new;
			new->next = NULL;
		}
	}
	else
		*alst = new;
}
