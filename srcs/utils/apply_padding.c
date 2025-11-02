/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:28:00 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/02 22:36:48 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_padlen(size_t num_len, t_format fmt)
{
	size_t	pad_len;

	pad_len = 0;
	if (fmt.width > num_len)
		pad_len = fmt.width - num_len;
	else
		pad_len = 0;
	return (pad_len);
}

static size_t	padding_str(char dest, size_t count, char c)
{
	size_t	i;
	size_t	pad_len;

	i = count;
	pad_len = get_padlen(len, fmt);
	while (i < pad_len)
	{
		dest[i] = c;
		i ++;
	}
	return (i);
}

static size_t	strcpy_and_len(char dest, const char src, size_t count)
{
	size_t	i;

	i = 0;
	while (src)
	{
		dest[count + i] = src[i];
		i ++;
	}
	return (i);
}

char	*apply_padding(const char *str, t_format fmt)
{
	size_t	len;
	char	*res;
	size_t	pad_len;
	char	c;
	size_t	count;

	len = ft_strlen(str);
	pad_len = get_padlen(len, fmt);
	if (fmt.padding == PAD_ZERO)
		c = '0';
	else
		c = ' ';
	res = malloc(len + pad_len + 1);
	if (!res)
		return (NULL);
	count = 0;
	if (fmt.align == ALIGN_RIGHT)
		count += padding_str(res, count, c);
	count += strcpy_and_len(res, src, count);
	if (fmt.align == ALIGN_LEFT)
		count += padding_str(res, count, c);
	res[count] = '\0';
	return (res);
}
