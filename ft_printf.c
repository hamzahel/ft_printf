/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 17:31:57 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 18:19:18 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		valist;
	t_data		*data;
	int			checkconv;

	va_start(valist, str);
	data = malloc(sizeof(t_data));
	data->charcounter = 0;
	while (str && *str)
	{
		if (*str == '%' && *(++str))
		{
			if (!(checkconv = ft_printf_helper(str, valist, data)))
				break ;
			str += checkconv;
		}
		else if (*str)
		{
			ft_putchar_fd(*(str++), 1);
			data->charcounter++;
		}
	}
	free(data);
	va_end(valist);
	return (data->charcounter);
}
