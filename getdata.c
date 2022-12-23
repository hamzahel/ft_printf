/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:01:22 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/15 22:30:41 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_data *data)
{
	data->flag = 0;
	data->width = 0;
	data->pre_s = 0;
	data->pre = -1;
	data->type = 0;
	if (data->content != NULL)
	{
		data->content = NULL;
	}
}

void	get_flag(const char *str, t_data *data)
{
	while (*str && ft_strchr(FLAGS, *str))
	{
		if (*str == '-')
		{
			data->flag = '-';
			break ;
		}
		else if (*str == '0')
		{
			data->flag = '0';
		}
		str++;
	}
}

void	get_width(const char *str, t_data *data, va_list list)
{
	if (*str == '0')
		str++;
	while (*str && !is_conv(*str))
	{
		if (*str == '.')
			break ;
		else if (ft_isdigit(*str))
		{
			data->width = ft_atoi(str);
			break ;
		}
		else if (*str == '*')
		{
			data->width = va_arg(list, int);
			if (data->width < 0)
			{
				data->flag = '-';
				data->width *= -1;
			}
			break ;
		}
		str++;
	}
}

void	get_pre(const char *str, t_data *data, va_list list)
{
	while (*str && !is_conv(*str))
	{
		data->pre_s = (*str == '.') ? *str : 0;
		if (*str == '.' && ft_isdigit(*(str + 1)))
		{
			data->pre = ft_atoi(str + 1);
			break ;
		}
		else if (*str == '.' && *(str + 1) == '*')
		{
			data->pre = va_arg(list, int);
			if (data->pre < 0)
			{
				data->pre = -1;
				data->pre_s = 0;
			}
			break ;
		}
		else if (*str == '.' && !ft_isdigit(*(str + 1)))
		{
			data->pre = -1;
			break ;
		}
		str++;
	}
}

int		get_type(const char *str, t_data *data)
{
	int i;

	i = 0;
	while (*str)
	{
		if (is_conv(*str))
		{
			data->type = *str;
			return (i);
		}
		str++;
	}
	return (i);
}
