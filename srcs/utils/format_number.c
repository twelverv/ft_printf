/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:59:32 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/10 14:20:39 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_number(const char *num_str, long n, t_format fmt)
{
	char	*res;
	char	*tmp;
	char	*next;

	if ((fmt.specifier == 'x' || fmt.specifier == 'X') && n != 0)
		tmp = apply_hash(num_str, fmt);
	else
		tmp = ft_strdup(num_str);
	if (!tmp)
		return (NULL);
	next = apply_precision(tmp, fmt);
	free(tmp);
	if (!next)
		return (NULL);
	tmp = next;
	if (fmt.specifier == 'd' || fmt.specifier == 'i')
	{
		next = apply_sign(tmp, n, fmt);
		free(tmp);
		if (!next)
			return (NULL);
		tmp = next;
	}
	res = apply_padding(tmp, fmt);
	return (free(tmp), res);
}
