/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_with_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:06:21 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/29 12:46:04 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_with_format(unsigned int n, t_format fmt_info, int uppercase)
{
	char	*str;
	int		num_len;
	int		count;
	int		padding;
	int		zero_pad;

	str = ft_itoa_base(n, 16, uppercase);
	if (!str)
		return (0);
	num_len = 0;
	while (str[num_len])
		num_len++;
	if (fmt_info.flag_hash && n != 0)
		num_len += 2;
	zero_pad = 0;
	if (fmt_info.precision_specified && fmt_info.precision > num_len)
		zero_pad = fmt_info.precision - num_len;
	padding = fmt_info.width - (num_len + zero_pad);
	count = 0;
	if (!fmt_info.flag_minus)
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	if (fmt_info.flag_hash && n != 0)
	{
		if (uppercase)
			count += write(1, "0X", 2);
		else
			count += write(1, "0x", 2);
	}
	while (zero_pad-- > 0)
		count += write(1, "0", 1);
	if (fmt_info.flag_hash && n != 0)
		count += write(1, str, num_len - 2);
	else
		count += write(1, str, num_len);
	if (fmt_info.flag_minus)
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	free(str);
	return (count);
}
