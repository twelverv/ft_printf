/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_with_format.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:18:53 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/25 16:20:26 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent_with_format(t_format fmt_info)
{
	int	count;
	int	padding;

	count = 0;
	padding = fmt_info.width - 1;
	if (!fmt_info.flag_minus)
		while (padding-- > 0)
			count += write(1, " ", 1);

	count += write(1, "%", 1);

	if (fmt_info.flag_minus)
		while (padding-- > 0)
			count += write(1, " ", 1);

	return (count);
}
