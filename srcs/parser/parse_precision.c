/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:37:37 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/11 13:24:12 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*parse_precision_value(const char *fmt, \
	t_format_raw *fmt_info, va_list args)
{
	if (*fmt == '*')
	{
		fmt_info->precision = va_arg(args, int);
		if (fmt_info->precision < 0)
		{
			fmt_info->precision_specified = 0;
			fmt_info->precision = 0;
		}
		return (fmt + 1);
	}
	while (*fmt >= '0' && *fmt <= '9')
	{
		fmt_info->precision = fmt_info->precision * 10 + (*fmt - '0');
		fmt++;
	}
	return (fmt);
}

const char	*parse_precision(const char *fmt, t_format_raw *fmt_info, \
	va_list args)
{
	if (*fmt == '.')
	{
		fmt++;
		fmt_info->precision_specified = 1;
		fmt_info->precision = 0;
		if (*fmt == '*' || (*fmt >= '0' && *fmt <= '9'))
		{
			fmt = parse_precision_value(fmt, fmt_info, args);
			fmt_info->flag_zero = 0;
		}
		else
		{
			fmt_info->precision = 0;
			fmt_info->flag_zero = 0;
		}
	}
	return (fmt);
}
