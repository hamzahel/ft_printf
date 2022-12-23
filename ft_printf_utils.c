/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:49:32 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 16:50:16 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_helper(const char *str, va_list list, t_data *data)
{
	int	checkconv;

	checkconv = 0;
	checkconv = parsedata(str, data, list) + 1;
	if (checkconv == 0)
	{
		ft_display((char *)str, 0, data);
		return (0);
	}
	ft_printresult(data);
	free(data->content);
	return (checkconv);
}
