/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:52:04 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/28 13:58:14 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_padding(t_format fmt_info, int padding, char *str, int len)
{
	int		count;
	int		left_padding;
	int		right_padding;
	char	pad_char;

	count = 0;
	pad_char = ' ';
	if (fmt_info.flag_zero && !fmt_info.flag_minus && \
			!fmt_info.precision_specified)
		pad_char = '0';
	left_padding = 0;
	right_padding = 0;
	if (fmt_info.flag_minus)
		right_padding = padding;
	else
		left_padding = padding;
	while (left_padding > 0)
	{
		count += write(1, &pad_char, 1);
		left_padding--;
	}
	count += write(1, str, len);
	while (right_padding > 0)
	{
		count += write(1, " ", 1);
		right_padding--;
	}
	return (count);
}



static size_t	count_digits_unsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	size_t	len;

	len = count_digits_unsigned(n);
	res = malloc(sizeof(char) * (len + 1));
	while (len--)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

static size_t	count_digits_base(unsigned long long n, int base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char	*res;
	char	*digits;
	size_t	len;

	if (uppercase != 0)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = count_digits_base(n, base);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--len] = digits[n % base];
		n /= base;
	}
	return (res);
}
