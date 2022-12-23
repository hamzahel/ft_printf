/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printresult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:54:41 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 18:25:37 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints(t_data *d)
{
	char	*tmp;

	if (d->type == 's' && !d->content)
		d->content = ft_strdup("(null)");
	if (d->pre > 0)
	{
		tmp = d->content;
		d->content = ft_substr(tmp, 0, d->pre);
		free(tmp);
	}
	else if (d->pre_s == '.')
		d->content = ft_strdup("");
	if (d->type == 'c' && d->content[0] == '\0')
		d->width -= 1;
	if (d->flag == '0')
		ft_add0(d->content, d->width, d);
	else if (d->flag == '-')
		ft_addspace(d->content, d->width, d);
	else if (d->width > 0)
		ft_addspacewidth(d->content, d->width, d);
	else
		ft_display(d->content, (d->type == 'c'), d);
}

void	ft_printdxp(t_data *d)
{
	if (d->flag == '0')
		ft_add0(d->content, d->width, d);
	else if (d->flag == '-')
	{
		ft_addspace(d->content, d->width, d);
	}
	else if (d->width > 0)
		ft_addspacewidth(d->content, d->width, d);
	else if (d->pre == -1 && d->content[0] == '0' && d->pre_s == '.')
		ft_display("", 0, d);
	else
	{
		if (d->type == 'p')
			ft_display("0x", 0, d);
		ft_display(d->content, 0, d);
	}
}

void	ft_printdxp_pre(t_data *d)
{
	int	s;

	s = ((int)ft_strlen(d->content) > d->pre) ? ft_strlen(d->content) : \
		d->pre + (d->content[0] == '-');
	if (d->flag == '0')
	{
		ft_addspacewidth("", d->width - s, d);
		ft_add0(d->content, s, d);
	}
	else if (d->flag == '-')
	{
		ft_add0(d->content, s, d);
		ft_addspace("", d->width - s, d);
	}
	else if (d->width)
	{
		ft_addspacewidth("", d->width - s, d);
		ft_add0(d->content, s, d);
	}
	else
	{
		if (d->type == 'p')
			ft_display("0x", 0, d);
		ft_add0(d->content, s, d);
	}
}

void	ft_printresult(t_data *d)
{
	if (d->type == 's' || d->type == 'c' || d->type == '%')
		ft_prints(d);
	else if (d->pre <= 0 && d->pre_s == '.' && d->content[0] == '0')
	{
		free(d->content);
		d->content = ft_strdup("");
		ft_printdxp_pre(d);
	}
	else if (d->pre_s == '.' && d->pre >= 0)
		ft_printdxp_pre(d);
	else
		ft_printdxp(d);
}
