/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_with_format.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:55:11 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 18:36:08 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_with_format(unsigned int num, t_format fmt)
{
	char	*num_str;
	char	*res;
	int		count;

	count = 0;
	num_str = ft_utoa(num);
	if (!num_str)
		return (-1);
	res = format_number(num_str, num, fmt);
	if (!res)
		return (-1);
	free(num_str);
	count += write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
