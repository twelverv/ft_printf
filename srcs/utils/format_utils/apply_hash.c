/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:29:16 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/11 13:36:07 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_hash(const char *num_str, t_format fmt)
{
	char	*res;
	char	*prefix;

	prefix = "";
	if (!fmt.show_prefix)
		return (ft_strdup(num_str));
	if (ft_strcmp(num_str, "0") == 0)
		return (ft_strdup(num_str));
	if (fmt.specifier == 'x')
		prefix = "0x";
	else if (fmt.specifier == 'X')
		prefix = "0X";
	res = ft_strjoin(prefix, num_str);
	if (!res)
		return (NULL);
	return (res);
}
