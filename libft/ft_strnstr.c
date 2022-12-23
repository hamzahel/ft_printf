/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:07:49 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/09 20:29:45 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i])
	{
		y = 0;
		while (haystack[i + y] == needle[y] && len > (y + i) && needle[y])
		{
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
