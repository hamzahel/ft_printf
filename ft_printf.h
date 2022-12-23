/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 14:49:40 by hel-ayac          #+#    #+#             */
/*   Updated: 2020/02/17 16:46:42 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "-0"
# define PATTERN "-0.*0123456789csdiuxXp%"
# define CONV "csdiuxXp%"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_data
{
	char			flag;
	int				width;
	char			pre_s;
	int				pre;
	char			type;
	char			*content;
	int				charcounter;
}					t_data;

int					countmod(const char *str);
void				converttohex(long i, int mode);
int					ft_printf(const char *str, ...);
int					convindex(const char *str);
void				ft_display(char *str, int mode, t_data *data);
void				ft_addspace(char *str, int n, t_data *data);
void				ft_add0(char *str, int n, t_data *data);
void				ft_addspacewidth(char *str, int n, t_data *data);
int					numofdigit(int nbr);
int					numofdigithex(int nbr);
int					is_conv(char c);
int					ft_printf(const char *str, ...);
void				get_flag(const char *str, t_data *data);
void				get_width(const char *str, t_data *data, va_list list);
void				get_pre(const char *str, t_data *data, va_list list);
int					get_type(const char *str, t_data *data);
void				init(t_data *data);
int					parsedata(const char *str, t_data *data, va_list list);
void				get_content(t_data *data, va_list list);
void				ft_printc(t_data *data);
void				ft_prints(t_data *data);
void				ft_printresult(t_data *data);
int					ft_printf_helper(const char *str, va_list list, t_data \
		*data);

#endif
