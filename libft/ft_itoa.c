/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:34:27 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/15 22:12:17 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnum(long x, char *result, size_t i)
{
	if (x < 0)
	{
		result[0] = '-';
		ft_putnum(x * (-1), result, 1 + i);
		return ;
	}
	if (x >= 10)
		ft_putnum(x / 10, result, 1 + i);
	result[i] = x % 10 + '0';
}

char			*ft_itoa(long n)
{
	char	result[12];

	if (n == 0)
		return (ft_strdup("0"));
	ft_bzero(result, sizeof(result));
	ft_putnum(n, result, 0);
	return (ft_strdup(ft_strrev(result)));
}
