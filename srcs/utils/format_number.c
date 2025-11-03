/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:59:32 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 14:02:46 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_number(const char *num_str, long n, t_format fmt)
{
	char	*res;
	char	*tmp;
	char	*next;

	if (fmt.specifier == 'x' || fmt.specifier == 'X')
		tmp = apply_hash(num_str, fmt);
	else
		tmp = ft_strdup(num_str);
	if (!tmp)
		return (NULL);
	next = apply_sign(tmp, n, fmt);
	if (!next)
		return (NULL);
	free(tmp);
	tmp = apply_precision(next, fmt);
	free(next);
	if (!tmp)
		return (NULL);
	res = apply_padding(tmp, fmt);
	free(tmp);
	return (res);
}
