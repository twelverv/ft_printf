/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:29:16 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 11:35:48 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_hash(const char *num_str, t_format fmt)
{
	char	*res;
	char	*prefix;

	prefix = "";
	if (!fmt.show_prefix || ft_strncmp(num_str, "0", 1) == 0)
		return (ft_strdup(num_str));
	if (fmt.show_prefix && fmt.specifier == 'x')
		prefix = "0x";
	else if (fmt.show_prefix && fmt.specifier == 'X')
		prefix = "0X";
	res = ft_strjoin(prefix, num_str);
	if (!res)
		return (NULL);
	return (res);
}
