/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:09:00 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 17:00:23 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsedata(const char *str, t_data *data, va_list list)
{
	int	i;

	i = 0;
	init(data);
	get_flag(str, data);
	get_width(str, data, list);
	get_pre(str, data, list);
	get_type(str, data);
	get_content(data, list);
	i = convindex(str);
	return (i);
}
