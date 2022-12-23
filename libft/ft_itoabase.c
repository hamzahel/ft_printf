/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:27 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/13 21:48:10 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	printhex(int result, int mode)
{
	if (result == 10)
		return ((mode) ? 'A' : 'a');
	else if (result == 11)
		return ((mode) ? 'B' : 'b');
	else if (result == 12)
		return ((mode) ? 'C' : 'c');
	else if (result == 13)
		return ((mode) ? 'D' : 'd');
	else if (result == 14)
		return ((mode) ? 'E' : 'e');
	else if (result == 15)
		return ((mode) ? 'F' : 'f');
	else
		return (result + '0');
}

char	*ft_itoabase(long nbr, int mode)
{
	char *result;
	char *tmp;
	char *tmpchar;

	result = NULL;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr > 0)
	{
		tmp = result;
		tmpchar = ft_chartostr(printhex(nbr % 16, mode));
		nbr /= 16;
		result = (tmp) ? ft_strjoin(tmp, tmpchar) : ft_strdup(tmpchar);
		free(tmpchar);
		free(tmp);
	}
	return (ft_strrev(result));
}
