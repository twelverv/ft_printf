/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_with_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:01:36 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/25 16:58:32 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer_with_format(int n, t_format fmt_info)
{
	char	*str;
	int		num_len;
	int		count;
	int		padding;
	int		zero_pad;

	str = ft_itoa(n);
	if (!str)
		return (0);
	num_len = 0;
	while (str[num_len])
		num_len++;
	zero_pad = 0;
	if (fmt_info.precision_specified && fmt_info.precision > num_len)
		zero_pad = fmt_info.precision - num_len;
	padding = fmt_info.width - (num_len + zero_pad);
	count = 0;
	if (n >= 0)
	{
		if (fmt_info.flag_plus)
			count += write(1, "+", 1);
		else if (fmt_info.flag_space)
			count += write(1, " ", 1);
	}
	if (!fmt_info.flag_minus)
	{
		while (padding-- > 0)
		{
			if (fmt_info.flag_zero && !fmt_info.flag_minus
				&& !fmt_info.precision_specified)
				count += write(1, "0", 1);
			else
				count += write(1, " ", 1);
		}
	}
	while (zero_pad-- > 0)
		count += write(1, "0", 1);
	count += write(1, str, num_len);

	if (fmt_info.flag_minus)
	{
		while (padding-- > 0)
			count += write(1, " ", 1);
	}
	free(str);
	return (count);
}
