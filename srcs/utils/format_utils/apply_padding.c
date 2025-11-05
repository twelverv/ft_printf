/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:28:00 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 18:25:01 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static size_t	fill_padding(char *dest, size_t count, char c, size_t pad_len)
{
	size_t i;

	i = 0;
	while (i < pad_len)
	{
		dest[count + i] = c;
		i++;
	}
	return (i);
}

static size_t	copy_str_with_offset(char *dest, const char *src, size_t count)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dest[count + i] = src[i];
		i++;
	}
	return (i);
}

static size_t	get_padlen(size_t content_len, size_t width)
{
	if (width > content_len)
		return (width - content_len);
	return (0);
}

static size_t	pad_number_with_zeros(char *res, size_t pad_len, \
	const char *str)
{
	size_t count;

	count = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		res[0] = str[0];
		count = 1;
		count += fill_padding(res, count, '0', pad_len);
		count += copy_str_with_offset(res, str + 1, count);
	}
	else
	{
		count += fill_padding(res, count, '0', pad_len);
		count += copy_str_with_offset(res, str, count);
	}
	return (count);
}

char	*apply_padding(const char *str, t_format fmt)
{
	size_t	len;
	size_t	pad_len;
	size_t	count;
	char	c;
	char	*res;

	len = ft_strlen(str);
	pad_len = get_padlen(len, fmt.width);
	if (fmt.padding == PAD_ZERO)
		c = '0';
	else
		c = ' ';
	res = malloc(len + pad_len + 1);
	if (!res)
		return (NULL);
	count = 0;
	if (fmt.align == ALIGN_RIGHT)
	{
		if (fmt.padding == PAD_ZERO && (str[0] == '-' || str[0] == '+'))
			count = pad_number_with_zeros(res, pad_len, str);
		else
		{
			count += fill_padding(res, count, c, pad_len);
			count += copy_str_with_offset(res, str, count);
		}
	}
	else
	{
		count += copy_str_with_offset(res, str, count);
		count += fill_padding(res, count, ' ', pad_len);
	}
	res[count] = '\0';
	return (res);
}
