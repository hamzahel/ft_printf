/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:15:04 by hel-ayac          #+#    #+#             */
/*   Updated: 2019/11/04 19:25:07 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	c;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	c = 0;
	while (set[c] && i <= j)
	{
		if (s1[i] == set[c])
		{
			i++;
			c = 0;
		}
		if (s1[j] == set[c])
		{
			j--;
			c = 0;
		}
		if (s1[i] != set[c] && s1[j] != set[c])
			c++;
	}
	return (ft_substr(s1, i, (j - i + 1)));
}
