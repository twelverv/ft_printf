/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_with_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:43:05 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/04 17:30:26 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer_with_format(int num, t_format fmt)
{
	char	*num_str;
	char	*res;
	int		count;

	count = 0;
	num_str = ft_itoa_2(num);
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
