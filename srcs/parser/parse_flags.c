/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:23:33 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/11 12:54:21 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*parse_flags(const char *fmt, t_format_raw *fmt_info)
{
	while (*fmt == '-' || *fmt == '0' || *fmt == '#' \
		|| *fmt == ' ' || *fmt == '+')
	{
		if (*fmt == '-')
		{
			fmt_info->flag_minus = 1;
			fmt_info->flag_zero = 0;
		}
		else if (*fmt == '0' && !fmt_info->flag_minus)
			fmt_info->flag_zero = 1;
		else if (*fmt == '#')
			fmt_info->flag_hash = 1;
		else if (*fmt == ' ')
		{
			if (!fmt_info->flag_plus)
				fmt_info->flag_space = 1;
		}
		else if (*fmt == '+')
		{
			fmt_info->flag_plus = 1;
			fmt_info->flag_space = 0;
		}
		fmt++;
	}
	return (fmt);
}
