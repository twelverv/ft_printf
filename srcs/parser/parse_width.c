/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:37:49 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/24 11:47:07 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*parse_width(const char *fmt, t_format *fmt_info, va_list args)
{
	if (*fmt == '*')
	{
		fmt_info->width = va_arg(args, int);
		if (fmt_info->width < 0)
		{
			fmt_info->flag_minus = 1;
			fmt_info->width = -(fmt_info->width);
		}
		fmt++;
	}
	else
	{
		while (*fmt >= '0' && *fmt <= '9')
		{
			fmt_info->width = fmt_info->width * 10 + (*fmt - '0');
			fmt++;
		}
	}
	return (fmt);
}
