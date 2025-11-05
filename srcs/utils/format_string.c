/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:59:06 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 16:54:06 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_string(const char *str, t_format fmt)
{
	char	*res;
	char	*tmp;

	tmp = apply_precision_string(str, fmt);
	if (!tmp)
		return (NULL);
	res = apply_padding(tmp, fmt);
	free(tmp);
	if (!res)
		return (NULL);
	return (res);
}
