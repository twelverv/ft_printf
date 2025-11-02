/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:36:49 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/02 22:18:03 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_padlen(size_t num_len, t_format fmt)
{
	size_t	pad_len;

	pad_len = 0;
	if (fmt.precision_specified && fmt.precision > num_len)
		pad_len = fmt.precision - num_len;
	else
		pad_len = 0;
	return (pad_len);
}

static char	*strdup_with_sign(char *dest, const char src, char sign, \
	size_t pad_len)
{
	size_t	i;
	size_t	j;
	size_t	num_len;

	i = 0;
	j = 0;
	num_len = ft_strlen(src);
	if (sign)
		dest[i++] = sign;
	while (pad_len --)
		dest[i++] = '0';
	j = 0;
	while (j < num_len)
	{
		dest[i + j] = src[j];
		j ++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*apply_precision(const char *num_str, t_format fmt)
{
	size_t	num_len;
	size_t	pad_len;
	char	sign;
	char	*res;

	sign = 0;
	num_len = ft_strlen(num_str);
	if (num_str[0] == '-' || num_str[0] == '+')
	{
		sign = num_str[0];
		num_str ++;
		num_len --;
	}
	if (fmt.precision_specified && fmt.precision == 0 && num_len == 1 && \
		num_str[0] == '0')
		num_len = 0;
	pad_len = get_padlen(num_len, fmt);
	if (sign)
		res = malloc(num_len + pad_len + 2);
	else
		res = malloc(num_len + pad_len + 1);
	if (!res)
		return (NULL);
	res = strdup_with_sign(res, num_str, sign, pad_len);
	return (res);
}
