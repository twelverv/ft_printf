/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:13:36 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 14:17:25 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_char(char c, t_format fmt)
{
	char	str[2];
	char	*res;

	str[0] = c;
	str[1] = '\0';
	res = apply_padding(str, fmt);
	if (!res)
		return (NULL);
	return (res);
}
