/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_with_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:43:05 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/03 14:51:41 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer_with_format(int num, t_format fmt)
{
	char	*num_str;
	char	*res;
	size_t	len;

	num_str = ft_itoa(num);
	if (!num_str)
		return (-1);
	res = format_number(num_str, num, fmt);
	if (!res)
		return (-1);
	free(num_str);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
