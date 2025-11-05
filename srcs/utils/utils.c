/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:33:23 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 18:43:24 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	res[len] = '\0';
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
