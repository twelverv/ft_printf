/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_with_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:08:04 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/25 16:14:57 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer_with_format(void *ptr, t_format fmt_info)
{
	unsigned long long	addr;
	char				*str;
	int					len;
	int					count;
	int					padding;

	addr = (unsigned long long)ptr;
	str = ft_itoa_base(addr, 16, 0);
	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	len += 2;
	padding = fmt_info.width - len;
	count = 0;

	if (!fmt_info.flag_minus)
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	count += write(1, "0x", 2);
	count += write(1, str, len - 2);
	if (fmt_info.flag_minus)
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	free(str);
	return (count);
}
