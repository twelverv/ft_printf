/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_with_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:39:46 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/25 12:47:24 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string_with_format(char *str, t_format fmt_info)
{
	int	len;
	int	count;
	int	padding;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt_info.precision_specified && fmt_info.precision < len)
		len = fmt_info.precision;
	count = 0;
	padding = fmt_info.width - len;
	if (!fmt_info.flag_minus)
		while (padding-- > 0)
			count += write(1, " ", 1);
	count += write(1, str, len);
	if (fmt_info.flag_minus)
		while (padding-- > 0)
			count += write(1, " ", 1);
	return (count);
}
