/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_with_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:16:46 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/25 16:25:50 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char_with_format(char c, t_format fmt_info)
{
	int	count;
	int	padding;

	count = 0;
	padding = fmt_info.width - 1;
	if (!fmt_info.flag_minus)
	{
		while (padding > 0)
		{
			if (fmt_info.flag_zero)
				count += write(1, "0", 1);
			else
				count += write(1, " ", 1);
			padding--;
		}
	}
	count += write(1, &c, 1);
	if (fmt_info.flag_minus)
	{
		while (padding > 0)
		{
			count += write(1, " ", 1);
			padding--;
		}
	}
	return (count);
}
