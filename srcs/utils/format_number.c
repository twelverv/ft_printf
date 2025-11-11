/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:59:32 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/11 13:35:53 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_hash_sign(t_format fmt, char *next, char *tmp, long n)
{
	if ((fmt.specifier == 'x' || fmt.specifier == 'X') && n != 0)
	{
		next = apply_hash(tmp, fmt);
		free(tmp);
		if (!next)
			return (NULL);
		tmp = next;
	}
	if (fmt.specifier == 'd' || fmt.specifier == 'i')
	{
		next = apply_sign(tmp, n, fmt);
		free(tmp);
		if (!next)
			return (NULL);
		tmp = next;
	}
	return (tmp);
}

char	*format_number(const char *num_str, long n, t_format fmt)
{
	char	*res;
	char	*tmp;
	char	*next;

	next = apply_precision(num_str, fmt);
	if (!next)
		return (NULL);
	tmp = next;
	tmp = format_hash_sign(fmt, next, tmp, n);
	res = apply_padding(tmp, fmt);
	free(tmp);
	return (res);
}

//char	*format_number(const char *num_str, long n, t_format fmt)
//{
//	char	*res;
//	char	*tmp;
//	char	*next;

//	if (fmt.precision_specified)
//		fmt.padding = PAD_SPACE;
//	if ((fmt.specifier == 'x' || fmt.specifier == 'X') && n != 0)
//		tmp = apply_hash(num_str, fmt);
//	else
//		tmp = ft_strdup(num_str);
//	if (!tmp)
//		return (NULL);
//	next = apply_precision(tmp, fmt);
//	free(tmp);
//	if (!next)
//		return (NULL);
//	tmp = next;

//	// 🔹符号(+,-, )の適用（整数のみ）
//	if (fmt.specifier == 'd' || fmt.specifier == 'i')
//	{
//		next = apply_sign(tmp, n, fmt);
//		free(tmp);
//		if (!next)
//			return (NULL);
//		tmp = next;
//	}

//	// 🔹パディング適用（ここで0埋め or 空白）
//	res = apply_padding(tmp, fmt);
//	free(tmp);
//	return (res);
//}
