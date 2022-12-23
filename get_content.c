/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:21:01 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 16:00:27 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_uint(int n)
{
	if (n >= 0)
		return (n);
	return (4294967295 + n + 1);
}

void	get_content(t_data *data, va_list list)
{
	int		mode;

	if (data->type == 'c')
		data->content = ft_chartostr(va_arg(list, int));
	else if (data->type == 's')
		data->content = ft_strdup(va_arg(list, char *));
	else if (data->type == 'd' || data->type == 'i')
		data->content = ft_itoa((long)va_arg(list, int));
	else if (data->type == 'u')
		data->content = ft_itoa(ft_uint(va_arg(list, unsigned int)));
	else if (data->type == 'x' || data->type == 'X')
	{
		mode = (data->type == 'X') ? 1 : 0;
		data->content = ft_itoabase(va_arg(list, unsigned int), mode);
	}
	else if (data->type == 'p')
		data->content = ft_itoabase(va_arg(list, unsigned long), 0);
	else if (data->type == '%')
		data->content = ft_strdup("%");
}
