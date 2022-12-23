/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:44:33 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 18:54:39 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display(char *str, int mode, t_data *data)
{
	if (mode)
	{
		ft_putchar_fd(*str, 1);
		data->charcounter++;
	}
	else
	{
		ft_putstr_fd(str, 1);
		data->charcounter += ft_strlen(str);
	}
}

void	ft_add0(char *str, int n, t_data *data)
{
	int i;
	int y;

	i = ft_strlen(str);
	y = 0;
	if (str[0] == '-')
	{
		ft_display("-", 1, data);
		str++;
	}
	if (data->type == 'p' && (str[0] || data->pre_s) && data->width > 0)
		ft_display("0x", 0, data);
	i += ((data->type == 'p' && data->pre_s == 0) ? 2 : 0);
	while (n - i > y)
	{
		ft_display("0", 1, data);
		y++;
	}
	ft_display(str, data->type == 'c', data);
}

void	ft_addspace(char *str, int n, t_data *data)
{
	int i;
	int y;

	i = ft_strlen(str);
	y = 0;
	if (data->type == 'p' && str[0] != '\0')
		ft_display("0x", 0, data);
	i += (data->type == 'p' ? 2 : 0);
	ft_display(str, data->type == 'c', data);
	while (n - i > y)
	{
		ft_display(" ", 1, data);
		y++;
	}
}

void	ft_addspacewidth(char *str, int n, t_data *data)
{
	int i;
	int y;

	i = ft_strlen(str);
	y = 0;
	i += (data->type == 'p' ? 2 : 0);
	while (n - i > y)
	{
		ft_display(" ", 1, data);
		y++;
	}
	if (data->type == 'p' && str[0] != '\0')
		ft_display("0x", 0, data);
	ft_display(str, data->type == 'c', data);
}
