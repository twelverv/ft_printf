/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_with_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:38:37 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 14:45:51 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string_with_format(const char *str, t_format fmt)
{
	char	*res;
	char	*tmp;
	int		len;

	res = format_string(str, fmt);
	if (!res)
		return (-1);
	if (!res)
		return (0);
	len = ft_strlen(res);
	tmp = res;
	while (*tmp)
	{
		write(1, tmp, 1);
		tmp ++;
	}
	free(res);
	return (len);
}
