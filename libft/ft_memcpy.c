/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 00:19:23 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/08 00:20:31 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int					i;
	unsigned char		*s1;
	const unsigned char	*s2;

	i = 0;
	if (str1 == str2)
		return (str1);
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (n == 0)
		return (str1);
	s1 = str1;
	s2 = str2;
	while ((n--) && ((s2[i] || s1[i])))
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
