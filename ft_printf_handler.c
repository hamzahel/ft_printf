/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:24:45 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 16:57:02 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numofdigithex(int nbr)
{
	int result;

	result = 1;
	while (nbr > 16)
	{
		nbr /= 16;
		result++;
	}
	return (result);
}

int	is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'x' || c == 'X' ||\
			c == 'p' || c == 'i' || c == 'u' || c == '%');
}

int	numofdigit(int nbr)
{
	int result;
	int count;

	result = 1;
	count = 1;
	while (nbr > 10)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	convindex(const char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_strchr(PATTERN, str[i]))
	{
		if (ft_strchr(CONV, str[i]))
			return (i);
		i++;
	}
	return (-1);
}
